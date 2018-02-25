pragma solidity ^0.4.0;

contract Voting {
    mapping (bytes32 => uint8) public votesReceived;
    bytes32[] public candidateList;
                
    function Voting(bytes32 [] candidateNames) public {
        candidateList = candidateNames;
    } 
                                    
    function totalVotesFor(bytes32 candidate) public constant returns (uint8) {
        require(validCandiate(candidate));
        return votesReceived[candidate];
    }
                                                                
    function voteForCandidate(bytes32 candidate) public {
        require(validCandiate(candidate));
        votesReceived[candidate] += 1;
    }
                                                                                            
    function validCandiate(bytes32 candidate) public returns (bool) {
        for (uint i = 0; i < candidateList.length; i++) {
            if (candidateList[i] == candidate) {
                return true;
            }
        }
        return false;
    }

}
