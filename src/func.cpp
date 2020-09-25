#include <stdio.h>
#include "Controller.h"

void func(void)
{
	Controller *pController;
	int32_t r;

	pController = new Controller();
	if(pController != nullptr)
	{
		r = pController->Initiate();
		if(r == 0)
		{
			r = pController->Execute();

			//printf("Execute Ret=%d\n", r);

			pController->Terminate();
		}

		delete pController;
		pController = nullptr;
	}

    return;
}

