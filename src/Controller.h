#include <stdio.h>
#include <stdint.h>
#include "RandomString.h"

class Controller
{
////----------------------------------------------------------------
////変数
////----------------------------------------------------------------
public:
	int32_t mDummy;

private:
	int32_t mAvailable;

	RandomString mRandomString;

////----------------------------------------------------------------
////関数
////----------------------------------------------------------------
public:
	Controller();
	~Controller();

	////基本関数
	int32_t Initiate(void);
	void Terminate(void);
	int32_t Execute(void);

private:
	
};



