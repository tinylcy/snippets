package raft

//
// this is an outline of the API that raft must expose to
// the service (or tester). see comments below for
// each of these functions for more details.
//
// rf = Make(...)
//   create a new Raft server.
// rf.Start(command interface{}) (index, term, isleader)
//   start agreement on a new log entry
// rf.GetState() (term, isLeader)
//   ask a Raft for its current term, and whether it thinks it is leader
// ApplyMsg
//   each time a new entry is committed to the log, each Raft peer
//   should send an ApplyMsg to the service (or tester)
//   in the same server.
//

import (
	"braft/labrpc"
	//"net"
	"bytes"
	"encoding/gob"
	"fmt"
	"math/rand"
	"sync"
	"time"
)

// import "bytes"
// import "encoding/gob"

//
// as each Raft peer becomes aware that successive log entries are
// committed, the peer should send an ApplyMsg to the service (or
// tester) on the same server, via the applyCh passed to Make().
//
type ApplyMsg struct {
	Index       int
	Command     interface{}
	UseSnapshot bool   // ignore for lab2; only used in lab3
	Snapshot    []byte // ignore for lab2; only used in lab3
}

type Status int

const (
	FOLLOWER  Status = iota // value --> 0
	CANDIDATE               // value --> 1
	LEADER                  // value --> 2
)

const HEARTBEAT_TIME int = 50

//
// A Go object implementing a single Raft peer.
//
type Raft struct {
	mu        sync.Mutex          // Lock to protect shared access to this peer's state
	peers     []*labrpc.ClientEnd // RPC end points of all peers
	persister *Persister          // Object to hold this peer's persisted state
	me        int                 // this peer's index into peers[]

	// Your data here (2A, 2B, 2C).
	// Look at the paper's Figure 2 for a description of what
	// state a Raft server must maintain.
	logs []Entry

	commitIndex int
	lastApplied int

	nextIndex  []int
	matchIndex []int

	currentTerm int
	votedFor    int

	status       Status
	beLeader     chan bool
	timeToCommit chan bool
	grantVote    chan bool
	getHeartBeat chan bool

	applyCh   chan ApplyMsg
	voteCount int
}

type Entry struct {
	Index     int
	Term      int
	Command   interface{}
	Signature []byte
}

func (entry Entry) String() string {
	return fmt.Sprintf("Index: %d, Term: %d, Command: %v",
		entry.Index, entry.Term, entry.Command)
}

// return currentTerm and whether this server
// believes it is the leader.
func (rf *Raft) GetState() (int, bool) {

	var term int
	var isLeader bool
	// Your code here (2A).
	rf.lock()
	term = rf.currentTerm
	isLeader = rf.status == LEADER
	rf.unLock()

	return term, isLeader
}

func (rf *Raft) getLastEntry() Entry {
	return rf.logs[len(rf.logs)-1]
}

//
// save Raft's persistent state to stable storage,
// where it can later be retrieved after a crash and restart.
// see paper's Figure 2 for a description of what should be persistent.
//
func (rf *Raft) persist() {
	// Your code here (2C).
	// Example:
	// w := new(bytes.Buffer)
	// e := gob.NewEncoder(w)
	// e.Encode(rf.xxx)
	// e.Encode(rf.yyy)
	// data := w.Bytes()
	// rf.persister.SaveRaftState(data)
	w := new(bytes.Buffer)
	e := gob.NewEncoder(w)
	e.Encode(rf.currentTerm)
	e.Encode(rf.votedFor)
	e.Encode(rf.logs)
	data := w.Bytes()
	rf.persister.SaveRaftState(data)
}

//
// restore previously persisted state.
//
func (rf *Raft) readPersist(data []byte) {
	// Your code here (2C).
	// Example:
	// r := bytes.NewBuffer(data)
	// d := gob.NewDecoder(r)
	// d.Decode(&rf.xxx)
	// d.Decode(&rf.yyy)
	if data == nil || len(data) < 1 {
		// bootstrap without any state?
		return
	}
	r := bytes.NewBuffer(data)
	d := gob.NewDecoder(r)
	d.Decode(&rf.currentTerm)
	d.Decode(&rf.votedFor)
	d.Decode(&rf.logs)
}

//
// example RequestVote RPC arguments structure.
// field names must start with capital letters!
//
type RequestVoteArgs struct {
	// Your data here (2A, 2B).
	Term        int
	CandidateId int

	LastLogIndex int
	LastLogTerm  int
}

//
// example RequestVote RPC reply structure.
// field names must start with capital letters!
//
type RequestVoteReply struct {
	// Your data here (2A).
	Term        int
	VoteGranted bool
}

type AppendEntriesArgs struct {
	Term     int
	LeaderId int

	Entries           []Entry
	LeaderCommitIndex int

	PrevLogIndex int
	PrevLogTerm  int
	IsHeartbeat  bool
}

type AppendEntriesReply struct {
	Term      int
	Success   bool
	NextIndex int
}

type InstallSnapshotArgs struct {
	Term     int
	LeaderId int

	LastIncludedIndex int
	LastIncludedTerm  int

	Data []byte
}

type InstallSnapshotReply struct {
	Term    int
	Success bool
}

func (entry *AppendEntriesArgs) String() string {
	return fmt.Sprintf("Term: %d, LeaderId: %d, Entries: %v, LeaderCommitIndex: %d, PrevLogIndex: %d, PrevLogTerm: %d",
		entry.Term, entry.LeaderId, entry.Entries, entry.LeaderCommitIndex, entry.PrevLogIndex, entry.PrevLogTerm)
}

//
// example RequestVote RPC handler.
//
func (rf *Raft) RequestVote(args *RequestVoteArgs, reply *RequestVoteReply) {
	// Your code here (2A, 2B).
	rf.lock()
	defer rf.unLock()
	defer rf.persist()
	// println(strconv.Itoa(args.CandidateId) + " term " + strconv.Itoa(args.Term) + " request " + strconv.Itoa(rf.me) + " term " + strconv.Itoa(rf.currentTerm))

	// 如果投票请求的 Term 比 currentTerm 小，直接返回拒绝投票。
	if args.Term < rf.currentTerm {
		reply.Term = rf.currentTerm
		reply.VoteGranted = false
		return
	}

	// 如果投票请求的 Term 比 currentTerm 大，更新自己的 currentTerm，状态变更为 Follower，
	// 但是此时还不能马上投票，因为还需要判断 Candidate 的日志是否比当前节点新。
	if args.Term > rf.currentTerm {
		rf.currentTerm = args.Term
		rf.status = FOLLOWER
		rf.votedFor = -1
	}

	reply.Term = rf.currentTerm

	// 如果已经给其他的 Candidate 投过票了，直接返回拒绝投票。
	if rf.votedFor != -1 && rf.votedFor != args.CandidateId {
		reply.VoteGranted = false
		return
	}

	// 当前节点最后一个日志项的 Index 和 Term。
	receiverLastIndex := rf.getLastEntry().Index
	receiverLastTerm := rf.getLastEntry().Term

	// 如果投票请求中的 Term 比当前节点 LastTerm 大，投票。
	// 如果 Term 相同，但是请求中的 Index 更大，投票。
	if (args.LastLogTerm > receiverLastTerm) ||
		(args.LastLogTerm == receiverLastTerm && args.LastLogIndex >= receiverLastIndex) {
		rf.grantVote <- true // 一旦投了票，重置计时器：向 grantVote Channel 中写入一条消息
		rf.votedFor = args.CandidateId
		reply.VoteGranted = true
	} else {
		reply.VoteGranted = false
	}

	//println(strconv.Itoa(args.CandidateId) + " request " + strconv.Itoa(rf.me) + " over")
}

func (rf *Raft) AppendEntries(args *AppendEntriesArgs, reply *AppendEntriesReply) {
	rf.lock()
	defer rf.unLock()
	defer rf.persist()

	if !args.IsHeartbeat {
		fmt.Printf("Follower: %d, args: %v\n", rf.me, args)
	}

	if args.IsHeartbeat {
		//println(strconv.Itoa(rf.me) + " recive heartbeat")
	} else {
		//println(strconv.Itoa(rf.me) + " recive append entry")
	}
	//println("rf.currentTerm" + strconv.Itoa(rf.currentTerm))
	//println("args.Term" + strconv.Itoa(args.Term))

	// 如果 args 的 Term 小于 currentTerm，直接返回。
	if args.Term < rf.currentTerm {
		reply.Term = rf.currentTerm
		reply.Success = false
		reply.NextIndex = rf.getLastEntry().Index + 1
		return
	}

	// 也算心跳。
	rf.getHeartBeat <- true

	// 如果 args 的 Term 比 currentTerm 大，当前节点状态变更为 Follower。
	if args.Term > rf.currentTerm {
		rf.currentTerm = args.Term
		rf.status = FOLLOWER
		rf.votedFor = -1
	}

	reply.Term = rf.currentTerm // ???

	// 如果 Leader 的 PrevLogIndex 大于当前节点最后一个日志项的 Index，设置 NextIndex，并返回。
	if args.PrevLogIndex > rf.getLastEntry().Index {
		reply.Success = false
		reply.NextIndex = rf.getLastEntry().Index + 1
		return
	}

	if rf.logs[args.PrevLogIndex].Term != args.PrevLogTerm {
		reply.Success = false
		term := rf.logs[args.PrevLogIndex].Term
		for i := args.PrevLogIndex - 1; i >= 0; i-- {
			if rf.logs[i].Term != term {
				reply.NextIndex = i + 1
				break
			}
		}
		return
	}

	rf.logs = rf.logs[:args.PrevLogIndex+1]
	if !args.IsHeartbeat {
		rf.logs = append(rf.logs, args.Entries...)
		//println(strconv.Itoa(rf.me) + " append " + strconv.Itoa(len(args.Entries)) + " entry")
	}

	if rf.commitIndex < args.LeaderCommitIndex {
		if args.LeaderCommitIndex < rf.getLastEntry().Index {
			rf.commitIndex = args.LeaderCommitIndex
		} else {
			rf.commitIndex = rf.getLastEntry().Index
		}
		rf.timeToCommit <- true
	}

	//println("rf " + strconv.Itoa(rf.me) + " len logs " + strconv.Itoa(len(rf.logs)))
	//println("rf " + strconv.Itoa(rf.me) + " commitIndex " + strconv.Itoa(rf.commitIndex))
	//println("rf " + strconv.Itoa(rf.me) + " last applied " + strconv.Itoa(rf.lastApplied))
	reply.Success = true
}

func (rf *Raft) applyCommand(entry Entry) {
	applyCh := ApplyMsg{}
	applyCh.Index = entry.Index
	applyCh.Command = entry.Command
	rf.applyCh <- applyCh
	//println(strconv.Itoa(rf.me) + " apply ***************************** " + strconv.Itoa(entry.Command.(int)))
	rf.lastApplied++
}

//
// example code to send a RequestVote RPC to a server.
// server is the index of the target server in rf.peers[].
// expects RPC arguments in args.
// fills in *reply with RPC reply, so caller should
// pass &reply.
// the types of the args and reply passed to Call() must be
// the same as the types of the arguments declared in the
// handler function (including whether they are pointers).
//
// The labrpc package simulates a lossy network, in which servers
// may be unreachable, and in which requests and replies may be lost.
// Call() sends a request and waits for a reply. If a reply arrives
// within a timeout interval, Call() returns true; otherwise
// Call() returns false. Thus Call() may not return for a while.
// A false return can be caused by a dead server, a live server that
// can't be reached, a lost request, or a lost reply.
//
// Call() is guaranteed to return (perhaps after a delay) *except* if the
// handler function on the server side does not return.  Thus there
// is no need to implement your own timeouts around Call().
//
// look at the comments in ../labrpc/labrpc.go for more details.
//
// if you're having trouble getting RPC to work, check that you've
// capitalized all field names in structs passed over RPC, and
// that the caller passes the address of the reply struct with &, not
// the struct itself.
//
func (rf *Raft) sendRequestVote(server int, args *RequestVoteArgs, reply *RequestVoteReply) bool {
	// 发送 RPC 请求。
	ok := rf.peers[server].Call("Raft.RequestVote", args, reply)
	rf.lock()
	defer rf.unLock()
	//fmt.Printf("%d send request to %d\n", rf.me, index)

	// 如果请求发送失败，直接返回。
	if !ok {
		return ok
	}

	// 如果当前节点不是出于 Candidate 状态，直接返回
	if rf.status != CANDIDATE {
		return ok
	}

	// 如果 RPC 请求中的 Term 不等于 currentTerm，直接返回。
	if args.Term != rf.currentTerm {
		return ok
	}

	// 如果收到的响应中的 Term 大于 currentTerm，更新 currentTerm，并变更状态为 Follower。
	if reply.Term > rf.currentTerm {
		rf.currentTerm = reply.Term
		rf.votedFor = -1 // 重置 votedFor，表示自己还没投过票
		rf.status = FOLLOWER
		rf.persist()
		return ok
	}

	// 如果成功收到投票
	if reply.VoteGranted && rf.status == CANDIDATE {
		rf.voteCount++
		// 如果收到大部分节点的投票，向 beLeader Channel 中发送一个消息
		if rf.voteCount > len(rf.peers)/2 {
			//println(strconv.Itoa(rf.me) + " get leader ----------")
			rf.beLeader <- true
		}
	}
	return ok
}

func (rf *Raft) sendAppendEntries(server int, args *AppendEntriesArgs, reply *AppendEntriesReply) bool {
	// 发送 RPC 请求。
	ok := rf.peers[server].Call("Raft.AppendEntries", args, reply)
	rf.lock()
	defer rf.unLock()

	// 如果 RPC 请求失败，直接返回。
	if !ok {
		return ok
	}

	// 如果当前节点不是 Leader，直接返回。
	if rf.status != LEADER {
		return ok
	}

	// 如果 args 中的 Term 不等于 currentTerm，直接返回。
	if args.Term != rf.currentTerm {
		return ok
	}

	if !args.IsHeartbeat {
		//fmt.Printf("%d send entry to %d \n", rf.me, server)
	}

	// 如果响应中的 Term 大于 Leader 的 currentTerm，Leader 设置 Term，并变更状态为 Follower，然后返回。
	if reply.Term > rf.currentTerm {
		rf.currentTerm = reply.Term
		//fmt.Printf("---------------------------------------------------------------------- leader %d become follower\n", rf.me)
		rf.status = FOLLOWER
		rf.votedFor = -1
		rf.persist()
		return ok
	}

	if reply.Success {
		if !args.IsHeartbeat {
			rf.nextIndex[server] = args.Entries[len(args.Entries)-1].Index + 1
			rf.matchIndex[server] = rf.nextIndex[server] - 1
		}
	} else {
		rf.nextIndex[server] = reply.NextIndex
	}
	return ok
}

//
// the service using Raft (e.g. a k/v server) wants to start
// agreement on the next command to be appended to Raft's log. if this
// server isn't the leader, returns false. otherwise start the
// agreement and return immediately. there is no guarantee that this
// command will ever be committed to the Raft log, since the leader
// may fail or lose an election.
//
// the first return value is the index that the command will appear at
// if it's ever committed. the second return value is the current
// term. the third return value is true if this server believes it is
// the leader.
//
func (rf *Raft) Start(command interface{}, sig []byte) (int, int, bool) {
	fmt.Println("signature:", sig)
	index := -1
	term := -1
	isLeader := true

	rf.lock()
	// Your code here (2B).
	if rf.status == LEADER {
		//println(strconv.Itoa(rf.me) + " ------ start ----- cmd " + strconv.Itoa(command.(int)))
		index = rf.getLastEntry().Index + 1
		entry := Entry{index, rf.currentTerm, command, sig}
		rf.logs = append(rf.logs, entry)
		rf.persist()
	} else {
		isLeader = false
	}

	term = rf.currentTerm
	rf.unLock()
	return index, term, isLeader
}

//
// the tester calls Kill() when a Raft instance won't
// be needed again. you are not required to do anything
// in Kill(), but it might be convenient to (for example)
// turn off debug output from this instance.
//
func (rf *Raft) Kill() {
	// Your code here, if desired.
}

func getRandomExpireTime() time.Duration {
	return time.Duration(rand.Int63n(300-150)+150) * time.Millisecond
}

func election(rf *Raft) {
	rf.lock()
	// 自增 currentTerm
	rf.currentTerm++
	// 给自己投一票
	rf.votedFor = rf.me
	rf.persist()
	rf.unLock()

	// 广播投票请求
	go func() {
		broadcastRequestVote(rf)
	}()
}

func broadcastRequestVote(rf *Raft) {
	rf.lock()
	defer rf.unLock()
	rf.voteCount = 1
	for i := range rf.peers {
		if i != rf.me && rf.status == CANDIDATE {
			requestVoteArgs := RequestVoteArgs{rf.currentTerm, rf.me, rf.getLastEntry().Index, rf.getLastEntry().Term}
			result := RequestVoteReply{}
			go func(server int) {
				rf.sendRequestVote(server, &requestVoteArgs, &result)
			}(i)
		}
	}
}

func broadcastAppendEntries(rf *Raft) {
	//println("------ start broadcast append entry ------")
	rf.lock()
	defer rf.unLock()

	for N := rf.commitIndex + 1; N <= rf.getLastEntry().Index; N++ {
		count := 1
		for i := 0; i < len(rf.matchIndex); i++ {
			//fmt.Printf("%d ", rf.matchIndex[i])
			if rf.me != i && rf.matchIndex[i] >= N && rf.logs[N].Term == rf.currentTerm {
				count++
			}
			if count > len(rf.matchIndex)/2 {
				rf.commitIndex = N
				break
			}
		}
		//fmt.Printf("\n")
	}
	rf.timeToCommit <- true

	for i := range rf.peers {
		if i != rf.me && rf.status == LEADER {
			appendEntriesArgs := AppendEntriesArgs{}
			appendEntriesArgs.Term = rf.currentTerm
			appendEntriesArgs.LeaderId = rf.me
			//println("logs size " + strconv.Itoa(len(rf.logs)))
			//println("commit index " + strconv.Itoa(rf.commitIndex))
			//fmt.Printf("last log's Index %d, nextIndex[%d] %d\n", rf.logs[len(rf.logs) - 1].Index, i, rf.nextIndex[i])

			//baseIndex := rf.getBaseIndex()
			nextIndex := rf.nextIndex[i]
			//fmt.Printf("nextIndex[%d] %d\n", i, nextIndex)
			//if rf.nextIndex[i] > baseIndex {
			if rf.getLastEntry().Index >= nextIndex {
				appendEntriesArgs.Entries = make([]Entry, len(rf.logs[nextIndex:]))
				copy(appendEntriesArgs.Entries, rf.logs[nextIndex:])
				//appendEntriesArgs.Entries = rf.logs[nextIndex:]
				appendEntriesArgs.IsHeartbeat = false
			} else {
				appendEntriesArgs.Entries = make([]Entry, 0)
				appendEntriesArgs.IsHeartbeat = true
			}
			if nextIndex-1 < 0 || nextIndex-1 >= len(rf.logs) {
				//println(strconv.Itoa(rf.me) + " nextIndex[" + strconv.Itoa(i) + "] " + strconv.Itoa(nextIndex) + " len(logs) " + strconv.Itoa(len(rf.logs)))
			}
			appendEntriesArgs.PrevLogIndex = nextIndex - 1
			appendEntriesArgs.PrevLogTerm = rf.logs[appendEntriesArgs.PrevLogIndex].Term
			appendEntriesArgs.LeaderCommitIndex = rf.commitIndex
			result := AppendEntriesReply{}
			go func(server int) {
				rf.sendAppendEntries(server, &appendEntriesArgs, &result)
			}(i)
			//}
		}
	}
}

func (rf *Raft) lock() {
	rf.mu.Lock()
}

func (rf *Raft) unLock() {
	rf.mu.Unlock()
}

//
// the service or tester wants to create a Raft server. the ports
// of all the Raft servers (including this one) are in peers[]. this
// server's port is peers[me]. all the servers' peers[] arrays
// have the same order. persister is a place for this server to
// save its persistent state, and also initially holds the most
// recent saved state, if any. applyCh is a channel on which the
// tester or service expects Raft to send ApplyMsg messages.
// Make() must return quickly, so it should start goroutines
// for any long-running work.
//
func Make(peers []*labrpc.ClientEnd, me int, persister *Persister, applyCh chan ApplyMsg) *Raft {
	rf := &Raft{}
	rf.peers = peers
	rf.persister = persister
	rf.me = me

	// Your initialization code here (2A, 2B, 2C).
	rf.currentTerm = 0
	rf.votedFor = -1

	rf.status = FOLLOWER
	rf.beLeader = make(chan bool, 1)
	rf.timeToCommit = make(chan bool, 1)
	rf.grantVote = make(chan bool, 1)
	rf.getHeartBeat = make(chan bool, 1)

	rf.logs = make([]Entry, 1)
	rf.commitIndex = 0
	rf.lastApplied = 0
	//rf.nextIndex = make([]int, 0)
	//rf.matchIndex = [len(rf.peers)]int{}

	rf.applyCh = applyCh

	// initialize from state persisted before a crash
	rf.readPersist(persister.ReadRaftState())
	go func(rf *Raft) {
		for {
			switch rf.status {
			case FOLLOWER:
				//println(strconv.Itoa(rf.me) + " start follower")
				select {
				case <-time.After(getRandomExpireTime()):
					rf.lock()
					//println(strconv.Itoa(rf.me) + " be Candidate")
					rf.votedFor = -1
					rf.status = CANDIDATE
					rf.persist()
					rf.unLock()
				case <-rf.getHeartBeat:
				// 一旦投了票，重置计时器
				case <-rf.grantVote:
				}
			case LEADER:
				broadcastAppendEntries(rf)
				time.Sleep(time.Duration(HEARTBEAT_TIME) * time.Millisecond)
			case CANDIDATE:
				election(rf)
				select {
				case <-time.After(getRandomExpireTime()):
				case <-rf.getHeartBeat:
					rf.lock()
					rf.status = FOLLOWER
					rf.votedFor = -1
					rf.persist()
					rf.unLock()
				case <-rf.beLeader:
					rf.lock()
					rf.status = LEADER
					rf.nextIndex = make([]int, len(rf.peers))
					for i := 0; i < len(rf.peers); i++ {
						rf.nextIndex[i] = rf.getLastEntry().Index + 1
					}
					rf.matchIndex = make([]int, len(rf.peers))
					for i := 0; i < len(rf.peers); i++ {
						rf.matchIndex[i] = 0
					}
					rf.unLock()
					//println(strconv.Itoa(rf.me) + " be leader ------------")
				}
			}
		}

	}(rf)

	go func(rf *Raft) {
		for {
			select {
			case <-rf.timeToCommit:
				rf.lock()
				//println(strconv.Itoa(rf.me) + " rf.commitIndex " + strconv.Itoa(rf.commitIndex) + " rf.lastApplied " + strconv.Itoa(rf.lastApplied))
				//println("rf " + strconv.Itoa(rf.me) + " len logs " + strconv.Itoa(len(rf.logs)))
				//println("rf " + strconv.Itoa(rf.me) + " commitIndex " + strconv.Itoa(rf.commitIndex))
				//println("rf " + strconv.Itoa(rf.me) + " last applied " + strconv.Itoa(rf.lastApplied))

				for rf.lastApplied < rf.commitIndex && rf.lastApplied+1 < len(rf.logs) {
					//println(lastAppliedIndex)
					rf.applyCommand(rf.logs[rf.lastApplied+1])
				}
				rf.unLock()
			}
		}
	}(rf)

	return rf
}
