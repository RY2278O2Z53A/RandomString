#ifndef RdRand_H
#define RdRand_H

#include <stdio.h>
#include <stdint.h>

namespace Entropy
{

class RdRand
{
////----------------------------------------------------------------
////変数
////----------------------------------------------------------------
public:
	int32_t mDummy;

private:
	int32_t mAvailable;

////----------------------------------------------------------------
////関数
////----------------------------------------------------------------
public:
	RdRand();
	~RdRand();

	////基本関数
	int32_t Initiate(void);
	void Terminate(void);

	uint64_t GetRandomSeed(void);
	uint64_t GetRandomNumber(void);

private:

};

}//end of Entropy

#endif



