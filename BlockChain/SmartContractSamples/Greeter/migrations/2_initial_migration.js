var Mortal = artifacts.require("./Mortal.sol");

module.exports = function(deployer) {
  deployer.deploy(Mortal);
};
