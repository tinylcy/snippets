/**
 * An extreamly basic example of a solidity contract. 
 */
pragma solidity ^0.4.0;

contract Greeter {
    address creator;
    string greeting;
    
    function Greeter(string _greeting) public {
        creator = msg.sender;
        greeting = _greeting;
    }
    
    function greet() constant returns (string) {
        return greeting;
    }
    
    // This doesn't have anything to do with the act of greeting
    function getBlockNumber() constant returns (uint) {
        return block.number;
    }
    
    function setGreeting(string _newgreeting) {
        greeting = _newgreeting;
    }
    
    // Standard kill() function to recover funds
    function kill() {
        if (msg.sender == creator) {
            suicide(creator);   // Kill this contract and send remaining funds back to creator
        }
    }
    
}