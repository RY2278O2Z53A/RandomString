#include <stdio.h>
#include <stdint.h>
#include "RandomString.h"

class Controller
{
////----------------------------------------------------------------
////�ϐ�
////----------------------------------------------------------------
public:
	int32_t mDummy;

private:
	int32_t mAvailable;

	RandomString mRandomString;

////----------------------------------------------------------------
////�֐�
////----------------------------------------------------------------
public:
	Controller();
	~Controller();

	////��{�֐�
	int32_t Initiate(void);
	void Terminate(void);
	int32_t Execute(void);

private:
	
};



