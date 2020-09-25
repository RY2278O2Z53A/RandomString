#include <stdio.h>
#include <stdint.h>
#include "RdRand.h"

class RandomString
{
	const char *pEncodeCharacter62 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; //26+26+10=62
	const char *pEncodeCharacter36 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //26+10=36

////----------------------------------------------------------------
////�ϐ�
////----------------------------------------------------------------
public:
	int32_t mDummy;

private:
	int32_t mAvailable;
	Entropy::RdRand mRand;

////----------------------------------------------------------------
////�֐�
////----------------------------------------------------------------
public:
	RandomString();
	~RandomString();

	////��{�֐�
	int32_t Initiate(void);
	void Terminate(void);
	int32_t Execute(void);

private:

};



