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

	// stack growth after growing process size
	printf(1, "TEST5: ");

	sbrk(10000);

	ppid = getpid();
	pid = fork();

	if(pid==0){
		recursion(500);
		printf(1, "OK\n");
		kill(ppid);
		exit();
	}
	wait();
	printf(1, "FAIL\n");
	exit();
}
