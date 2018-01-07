var Voting = artifacts.require("./Voting.sol");

var user1 = "0xae98fe355a4a922f57c2125be5b4ab8385f6cbb6"
var user2 = "0xec6cf4eb5047e74c7126505c3bd27ac3105fc3a6"
var user3 = "0x9bc93e521d8e8e45b01f1241632d3ef92f5563b3"

module.exports = function(deployer) {
  deployer.deploy(Voting, [user1, user2, user3]);
};
