#include <stdio.h>

void func(void);

int main(int argc, char *argv[], char *envp[])
{
	//printf("pointer size = %d\n", (int)(sizeof(void*)));
	
	func();

    return 0;
}

