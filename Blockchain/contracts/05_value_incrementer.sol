/**
 * This example demonstrates a simple non-contract (transactional) function you can call from geth.
 */ 
 
 pragma solidity ^0.4.0;
 
 contract Incrementer {
    address creator;
    uint iteration;
     
    function Incrementer() public {
        creator = msg.sender;
        iteration = 0;
    }
     
    function increment() public {
        iteration += 1;
    }
     
    
    function getIteration() public returns (uint) {
        return iteration;
    }

 }