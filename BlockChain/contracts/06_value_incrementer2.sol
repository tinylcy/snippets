/**
 * This example demonstrates a simple non-constant (transactional) function you call from geth.
 * increment() function takes one parameter and merely increments the "iteration" value by that much.
 */ 
 
 pragma solidity ^0.4.0;
 
 contract Incrementer2 {
     address creator;
     uint iteration;
     string whatHappened;
     
     function Incrementer2() {
         creator = msg.sender;
         iteration = 0;
         whatHappened = "constructor executed";
     }
     
     function increment(uint howMuch) {
         if (howMuch == 0) {
             iteration += 1;
             whatHappened = "howMuch was zero. Incremented by 1.";
         } else {
             iteration += howMuch;
             whatHappened = "howMuch was nonzero. Incremented by its value.";
         }
     }
     
     function getWhatHappened() constant returns (string) {
         return whatHappened;
     }
     
     function getIteration() constant returns (uint) {
         return iteration;
     }
     
 }