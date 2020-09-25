#include "RdRand.h"
#include <intrin.h>
#include <immintrin.h>
#include <xmmintrin.h>

namespace Entropy
{

RdRand::RdRand()
	: mDummy(0)
	, mAvailable(0)
{
}


RdRand::~RdRand()
{
	Terminate();
}

////----------------------------------------------------------------
////
////----------------------------------------------------------------

int32_t RdRand::Initiate(void)
{
	int32_t x[4];
	int32_t Genu = 0x756E6547;
	int32_t ineI = 0x49656E69;
	int32_t ntel = 0x6C65746E;
	uint64_t v;

	__cpuid(x, 0);

	if((x[1] != Genu) || (x[2] != ntel) || (x[3] != ineI))
	{
		//printf("Not Intel\n");
		return 1;
	}
	else
	{
		//RDRAND
		__cpuid(x, 1);

		if((x[2] & 0x40000000) != 0)
		{
			//printf("RDRAND OK\n");

			////Test
			v = GetRandomNumber();
			//printf("rdrand = %020llu\n", v);
		}
		else
		{
			//printf("NO RDRAND\n");
			return 2;
		}

		//RDSEED
		__cpuid(x, 7);
		if((x[1] & 0x00040000) != 0)
		{
			//printf("RDSEED OK\n");

			////Test
			v = GetRandomSeed();
			//printf("raseed = %020llu\n", v);
		}
		else
		{
			//printf("NO RDSEED\n");
			return 3;
		}
	}

	mAvailable = 1;

	////‹ó‰ñ‚µ
	v = GetRandomNumber();

	return 0;
}

void RdRand::Terminate(void)
{
	mAvailable = 0;

	return;
}

////----------------------------------------------------------------
////
////----------------------------------------------------------------

uint64_t RdRand::GetRandomNumber(void)
{
	int32_t r;
	uint64_t v;

	do
	{
		r = _rdrand64_step(&v);
	}while(r == 0);

	return v;
}

uint64_t RdRand::GetRandomSeed(void)
{
	int32_t r;
	uint64_t v;

	r = _rdseed64_step(&v);
	while(r == 0)
	{
		_mm_pause();
		r = _rdseed64_step(&v);
	}

	return v;
}


////----------------------------------------------------------------
////
////----------------------------------------------------------------

}//end of Entropy

