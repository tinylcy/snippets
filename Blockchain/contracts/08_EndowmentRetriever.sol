pragma solidity ^0.4.0;

contract EndowmentRetriever {
    address creator;
    uint contract_creation_value;
    
    function EndowmentRetriever() public {
        creator = msg.sender;
        contract_creation_value = msg.value;
    }
    
    function getContractCreationValue() constant returns (uint) {
        return contract_creation_value;
    }
    
    function sendOneEtherHome() public {
        creator.send(1000000000000000000);   // Send 1 ETH home
    }
    
    function getCreator() public constant returns (address) {
        return creator;
    }
}