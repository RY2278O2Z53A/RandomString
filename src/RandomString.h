#include <stdio.h>
#include <stdint.h>
#include "RdRand.h"

class RandomString
{
	const char *pEncodeCharacter62 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; //26+26+10=62
	const char *pEncodeCharacter36 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //26+10=36

////----------------------------------------------------------------
////変数
////----------------------------------------------------------------
public:
	int32_t mDummy;

private:
	int32_t mAvailable;
	Entropy::RdRand mRand;

////----------------------------------------------------------------
////関数
////----------------------------------------------------------------
public:
	RandomString();
	~RandomString();

	////基本関数
	int32_t Initiate(void);
	void Terminate(void);
	int32_t Execute(void);

private:

};



