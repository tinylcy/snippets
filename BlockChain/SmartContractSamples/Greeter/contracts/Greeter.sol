pragma solidity ^0.4.0;

import "./Mortal.sol";

contract Greeter is Mortal {
    string greeting;

    function Greeter(string _greeting) public {
        greeting = _greeting;
    }

    function greet() constant returns (string) {
        return greeting;
    }
}
