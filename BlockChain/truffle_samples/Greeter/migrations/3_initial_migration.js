var Greeter = artifacts.require("./Greeter.sol");

var _greeting = "tinylcy";

module.exports = function(deployer) {
  deployer.deploy(Greeter, _greeting);
};
