pragma solidity ^0.4.0;

contract TypeStorage {
    
    string public msg = "tinylcy";

    function f() {
        modify(msg);
    }

    function modify(string storage _msg) internal {
        bytes(_msg)[0] = 'T';
    }

    function getMsg() returns (string) {
        return msg;
    }

}
