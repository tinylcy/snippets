# Hyperledger Fabric PBFT Test

## Preparation

### Download Images

#### Option 1: Use community images
The community [images](https://hub.docker.com/r/hyperledger/) are available at dockerhub, use at your own choice.

```bash
$ docker pull hyperledger/fabric-peer:x86_64-0.6.1-preview \
  && docker pull hyperledger/fabric-membersrvc:x86_64-0.6.1-preview \
  && docker pull yeasy/blockchain-explorer:latest \
  && docker tag hyperledger/fabric-peer:x86_64-0.6.1-preview hyperledger/fabric-peer \
  && docker tag hyperledger/fabric-peer:x86_64-0.6.1-preview hyperledger/fabric-baseimage \
  && docker tag hyperledger/fabric-membersrvc:x86_64-0.6.1-preview hyperledger/fabric-membersrvc
```

#### Option 2: Use IBM certificated images
IBM also provides some tested [images](http://www-31.ibm.com/ibm/cn/blockchain/index.html), available at [dockerhub](http://www-31.ibm.com/ibm/cn/blockchain/index.html), use at your own choice.

```bash
$ docker pull ibmblockchain/fabric-peer:x86_64-0.6.1-preview \
  && docker pull ibmblockchain/fabric-membersrvc:x86_64-0.6.1-preview \
  && docker pull yeasy/blockchain-explorer:latest \
  && docker tag ibmblockchain/fabric-peer:x86_64-0.6.1-preview hyperledger/fabric-peer \
  && docker tag ibmblockchain/fabric-peer:x86_64-0.6.1-preview hyperledger/fabric-baseimage \
  && docker tag ibmblockchain/fabric-membersrvc:x86_64-0.6.1-preview hyperledger/fabric-membersrvc
```
#### Option 3: Use my images

Some tested dockerhub image with latest changes, Dockerfile provided.

```sh
$ docker pull yeasy/hyperledger-fabric-base:0.6-dp \
  && docker pull yeasy/hyperledger-fabric-peer:0.6-dp \
  && docker pull yeasy/hyperledger-fabric-membersrvc:0.6-dp \
  && docker pull yeasy/blockchain-explorer:latest \
  && docker tag yeasy/hyperledger-fabric-peer:0.6-dp hyperledger/fabric-peer \
  && docker tag yeasy/hyperledger-fabric-base:0.6-dp hyperledger/fabric-baseimage \
  && docker tag yeasy/hyperledger-fabric-membersrvc:0.6-dp hyperledger/fabric-membersrvc
```

## Usage

### 4-node Noops

Start a 4-node fabric cluster with Noops consensus.

```sh
$ cd noops; docker-compose -f 4-peers.yml up
```

### 4-node PBFT

Start a 4-node fabric cluster with PBFT consensus.

```sh
$ cd pbft; docker-compose -f 4-peers.yml up
```

### Test chaincode

After the cluster is synced successfully, you can validate by deploying, invoking or querying chaincode from the container or from the host.

```sh
$ docker exec -it pbft_vp0_1 bash
# peer chaincode deploy -p github.com/hyperledger/fabric/examples/chaincode/go/chaincode_example02 -c '{"Function":"init", "Args": ["a","100", "b", "200"]}'
```


