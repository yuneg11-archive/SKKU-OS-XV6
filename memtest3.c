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

	// stack growth test
	printf(1, "TEST3: ");

	ppid = getpid();
	pid = fork();

	if(pid==0){
		recursion(500);
		recursion(500);
		kill(ppid);
		printf(1, "OK\n");
		exit();
	}
	wait();
	printf(1, "FAIL\n");
	exit();
}
