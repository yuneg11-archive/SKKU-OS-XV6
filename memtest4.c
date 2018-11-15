#include "types.h"
#include "stat.h"
#include "user.h"
#include "memlayout.h"

void recursion(int n){
	if(n>0)
		recursion(n-1);
}

int
main(int argc, char **argv)
{
	int ppid, pid;

	// stack overflow test
	printf(1, "TEST4: ");

	ppid = getpid();
	pid = fork();

	if(pid==0){
		recursion(10000000);
		printf(1, "FAIL\n");
		kill(ppid);
		exit();
	}
	wait();
	printf(1, "OK\n");
	exit();
}
