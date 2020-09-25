#include <stdio.h>
#include <stdint.h>
#include "RandomString.h"

class Controller
{
////----------------------------------------------------------------
////ïœêî
////----------------------------------------------------------------
public:
	int32_t mDummy;

private:
	int32_t mAvailable;

	RandomString mRandomString;

////----------------------------------------------------------------
////ä÷êî
////----------------------------------------------------------------
public:
	Controller();
	~Controller();

	////äÓñ{ä÷êî
	int32_t Initiate(void);
	void Terminate(void);
	int32_t Execute(void);

private:
	
};



