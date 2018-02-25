/**
 * This is a very simple example of while loops.
 */ 
pragma solidity ^0.4.0;

contract BasicIterator {
    address creator;
    uint8[10] integers;
    
    function BasicIterator() public {
        creator = msg.sender;
        uint8 x = 0;
        while (x < integers.length) {
            integers[x] = x;
            x++;
        }
    }
    
    function getSum() constant returns (uint) {
        uint sum = 0;
        uint8 x = 0;
        while (x < integers.length) {
            sum += integers[x];
            x++;
        }
        return sum;
    }
}
