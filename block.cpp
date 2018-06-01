#include "block.h"
#include "sha256.h"
#include <ctime>
#include <iostream>


Block::Block(string data, string previousHash){

	this->data = data;
	this->previousHash = previousHash;
	this->timeStamp = time(0);
	this->hash = calculateHash();

}

Block::~Block(){}

string Block::calculateHash(){
	string calculatedHash = sha256(previousHash + to_string(timeStamp) + to_string(nonce) + data);
	return calculatedHash;
}

void Block::mineBlock(unsigned difficulty){
	string target = "";
	for(unsigned i = 0; i < difficulty; i++) target.append("0");
	while(hash.substr(0, difficulty) != target){
		nonce++;
		hash = calculateHash();
	}

	cout << "Block found!";
}

