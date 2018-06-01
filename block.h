#ifndef BLOCK_H_USED
#define BLOCK_H_USED

#define UINT_MAX 0xffffffff;

#include <string>

using namespace std;

class Block {
	
	private:
		unsigned nonce;
		long timeStamp;
		string data;


	public:
		Block(string data, string previousHash);
		~Block();

		string calculateHash();
		void mineBlock(unsigned difficulty);

		string hash;
		string previousHash;

};

#endif