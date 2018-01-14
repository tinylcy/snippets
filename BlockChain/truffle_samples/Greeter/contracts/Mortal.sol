pragma solidity ^0.4.0;

contract Mortal {
    address owner;

    function Mortal() {
        owner = msg.sender;
    }

    function kill() {
        if (msg.sender == owner) {
            selfdestruct(owner);
        }
    }
}
