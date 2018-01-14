/**
 * This example demonstrates that a contract can retrieve and store the
 * balance of its creator address.
 */ 
pragma solidity ^0.4.0;

contract CreatorBalanceChecker {
    address creator;
    uint creatorBalace;
    
    function CreatorBalanceChecker() public {
        creator = msg.sender;
        creatorBalace = creator.balance;    // msg is a global variable
    }
    
    function getContractAddress() constant returns (address) {
        return this;
    }
    
    // Return the creator's balance at the time this constract was created
    function getCreatorBalance() constant returns (uint) {
        return creatorBalace;
    }
    
    // Return the creator's balance now
    function getCreatorDotBalance() constant returns (uint) {
        return creator.balance;
    }
}
