/**
 * This example demonstrates a simple constant function you can call from geth.
 * increment() function takes two parameters and increments the iteration value by howMuch and also
 * set an arbitrary customValue.
 * 
 * Be careful, see below for how to make the call in geth.
 * incrementer3.increment.sendTransaction(3, 9, {from:eth.coinbase,gas:1000000});
 * Note that we needed more than the (geth) defalut gas of 90k this time. I chose 1m (unused gas is refunded anyway).
 * 
 */ 
 
 pragma solidity ^0.4.0;
 
 contract Incrementer3 {
     address creator;
     uint iteration;
     string whatHappened;
     uint customValue;
     
     function Incrementer3() public {
         creator = msg.sender;
         iteration = 0;
         whatHappened = "constructor executed";
     }
     
     function increment(uint howMuch, uint _customValue) public {
         customValue = _customValue;
         if (howMuch == 0) {
             iteration += 1;
             whatHappened = "howMuch was zero. Increment by 1. customValue also set.";
         } else {
             iteration += howMuch;
             whatHappened = "howMuch was nonzero. Increment by its value. customValue also set.";
         }
     }
     
     function getCustomValue() public constant returns (uint) {
         return customValue;
     }
     
     function getWhatHappened() public constant returns (string) {
         return whatHappened;
     }
     
     function getIteration() public constant returns (uint) {
         return iteration;
     }
 }