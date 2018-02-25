/**
 * This example demonstrates the various global variables available to contracts.
 */ 
 
 pragma solidity ^0.4.0;
 
 contract BasicInfoGetter {
     address creator;
     
     function BasicInfoGetter() public {
         creator = msg.sender;
     }
     
     // Return the data of a call to this function.
     function getMsgData() constant returns (bytes) {
         return msg.data;
     }
     
     function getMsgSender() constant returns (address) {
         return msg.sender;
     }
     
     // Return the amount of Wei sent with this call
     function getMsgValue() constant returns (uint) {
         return msg.value;
     }
 }