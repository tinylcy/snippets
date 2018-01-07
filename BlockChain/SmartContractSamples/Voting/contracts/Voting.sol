pragma solidity ^0.4.0;

contract Voting {
    mapping (address => uint8) public votesReceived;
    address[] public candidateList;    // 存储候选人名字的数组

    function Voting(address[] addrs) {
        candidateList = addrs;
    }

    function totalVotesFor(address candidate) constant returns (uint8) {
        require(validCandidate(candidate) == true);
        return votesReceived[candidate];
    }

    // 为某个候选人投票
    function voteForCandidate(address candidate) {
        assert(validCandidate(candidate) == true);
        votesReceived[candidate] += 1;
    }

    function getCandidateCount() constant returns (uint) {
       // return 3;
        return candidateList.length;
    }

    // 检索投票的姓名是不是候选人的名字
    function validCandidate(address candidate) constant returns (bool) {
        for (uint i = 0; i < candidateList.length; i++) {
            if (candidateList[i] == candidate) {
                return true;
            }
        }
        return false;
    }

    function compareStrings(string a, string b) returns (bool) {
        return keccak256(a) == keccak256(b);
    }
}
