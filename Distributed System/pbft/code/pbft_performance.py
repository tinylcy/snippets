import time
from hyperledger.client import Client

current_milli_time = lambda: int(round(time.time() * 1000))

c = Client(base_url="http://127.0.0.1:7050")

start = current_milli_time()
count = 100
chaincode_name = "d75bfee19774951550a2f771bd9c9a11bc466405e63a853ee0ee0163db3068465ce4aa749c9ebf183227a2ad0805fc6c6a3d0f9f9dc1d902503dbca3350d3245"

# print(c.chaincode_deploy())
# print(c.chaincode_query(chaincode_name=chaincode_name))

for i in range(count):
	result = c.chaincode_invoke(
		chaincode_name=chaincode_name,
		function="invoke", args=["a", "b", "100"])
	# print(result)

done = current_milli_time()
elapsed = done - start
print(1 / (elapsed / count / 1000), 'tps')

# mkdir $GOPATH/src/chaincode_example02 && cp $GOPATH/src/github.com/hyperledger/fabric/examples/chaincode/go/chaincode_example02/chaincode_example02.go $GOPATH/src/chaincode_example02/ && cd $GOPATH/src/chaincode_example02 && go build
