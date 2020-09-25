#include "Controller.h"

Controller::Controller()
	: mDummy(0)
	, mAvailable(0)
{
}


Controller::~Controller()
{
}

////----------------------------------------------------------------
////
////----------------------------------------------------------------

int32_t Controller::Initiate(void)
{
	int32_t r;

	r = mRandomString.Initiate();
	if(r != 0)
	{
		return 1;
	}

	mAvailable = 1;

	return 0;
}

void Controller::Terminate(void)
{
	mAvailable = 0;
	mRandomString.Terminate();

	return;
}

int32_t Controller::Execute(void)
{
	mRandomString.Execute();

	return 0;
}


////----------------------------------------------------------------
////
////----------------------------------------------------------------
