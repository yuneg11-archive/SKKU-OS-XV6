#include "types.h"
#include "stat.h"
#include "user.h"
#include "memlayout.h"

int
main(int argc, char **argv)
{
	int pid;

	// fork process with deallocated stacks after growing process size
	printf(1, "TEST2: ");

	sbrk(10000);

	pid = fork();

	if(pid<0){
		printf(1, "FAIL\n");
		exit();
	}

	if(pid==0)
		exit();
	else
		wait();

	printf(1, "OK\n");
	exit();
}
