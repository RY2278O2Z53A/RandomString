#include "RandomString.h"
//#include <intrin.h>
//#include <immintrin.h>
//#include <xmmintrin.h>

RandomString::RandomString()
	: mDummy(0)
	, mAvailable(0)
{
}


RandomString::~RandomString()
{
}

////----------------------------------------------------------------
////
////----------------------------------------------------------------

int32_t RandomString::Initiate(void)
{
	int32_t r;

	r = mRand.Initiate();
	if(r != 0)
	{
		return 1;
	}

	return 0;
}

void RandomString::Terminate(void)
{
	mRand.Terminate();

	return;
}

int32_t RandomString::Execute(void)
{
	uint64_t v;
	uint64_t u, x;
	int32_t i, j;

	////何種類か出力
	{
		v = mRand.GetRandomNumber();
		printf("Random\n  DEX: %020llu\n  HEX: %016llX\n", v, v);

		printf("  STR: ");
		u = v;
		for(i=0;i<11;i++)
		{
			x = u % 62;
			u = u / 62;

			printf("%c", pEncodeCharacter62[x]);
		}
		printf("\n");

		printf("  STR: ");
		u = v;
		for(i=0;i<12;i++)
		{
			x = u % 36;
			u = u / 36;

			printf("%c", pEncodeCharacter36[x]);
		}
		printf("\n");
		////最後の１桁は0以上〜4未満なので省略

		printf("\n");
	}
	
	////文字列だけ100個出力
	for(j=0;j<100;j++)
	{
		v = mRand.GetRandomNumber();

		printf("  STR: %02d: ", j);
		u = v;
		for(i=0;i<12;i++)
		{
			x = u % 36;
			u = u / 36;

			printf("%c", pEncodeCharacter36[x]);
		}
		printf("\n");
		////最後の１桁は0以上〜4未満なので省略
	}

	return 0;
}

////----------------------------------------------------------------
////
////----------------------------------------------------------------

