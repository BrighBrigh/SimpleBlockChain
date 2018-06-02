#include <iostream>
#include <vector>

#include "block.h"

using namespace std;

int main(){

	cout << "Starting...\n\n";

	unsigned difficulty = 5;
	vector<Block> blockChain;

	Block *tempBlock = new Block("Genesis", "0");
	blockChain.push_back(*tempBlock);
	cout << "Attempting to mine Genesis block...\n\n";
	blockChain.at(0).mineBlock(difficulty);

	cout << "\n\tHash:          " << blockChain.at(0).hash << "\n\tPrevious Hash: " << blockChain.at(0).previousHash
		<< "\n\tNonce:         " << blockChain.at(0).nonce << "\n\tTimeStamp:     " << blockChain.at(0).timeStamp << "\n\tData:          "
		<< blockChain.at(0).data;

	unsigned blockNumber = 1;

	while(1){

		Block *nextBlock = new Block("Block " + to_string(blockNumber), blockChain.at(blockNumber-1).hash);
		blockChain.push_back(*nextBlock);
		cout << "\n\nAttempting to mine next block...\n\n";

		blockChain.at(blockNumber).mineBlock(difficulty);

		cout << "\n\tHash:          " << blockChain.at(blockNumber).hash << "\n\tPrevious Hash: " << blockChain.at(blockNumber).previousHash
		<< "\n\tNonce:         " << blockChain.at(blockNumber).nonce << "\n\tTimeStamp:     " << blockChain.at(blockNumber).timeStamp << "\n\tData:          "
		<< blockChain.at(blockNumber).data;

		unsigned blockTime = blockChain.at(blockNumber).timeStamp - blockChain.at(blockNumber-1).timeStamp;
		cout << "\n\tTime to find:  " << blockTime << " seconds"; 
		

		blockNumber++;

	}

	return 0;
}