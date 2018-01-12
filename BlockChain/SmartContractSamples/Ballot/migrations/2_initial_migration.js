var Ballot = artifacts.require("./Ballot.sol");

var proposalNames = ["A", "B", "C", "D"];

module.exports = function(deployer) {
  deployer.deploy(Ballot, proposalNames);
};
