pragma solidity ^0.4.0;

contract TypeMemory {
    string msg = "tinylcy";

    function f() {
        modify(msg);
    }

    function modify(string _msg) {
        bytes(_msg)[0] = 'T';
    }

    function getMsg() public returns (string) {
        return msg;
    }
}
