#include "types.h"
#include "stat.h"
#include "user.h"
#include "memlayout.h"

int
main(int argc, char **argv)
{
	char *a;
	int ppid, pid;

	// invalid access over kernel space
	printf(1, "TEST6: ");

	for(a = (char *)(KERNBASE); a < (char *)(KERNBASE+2000000); a += 50000){
		ppid = getpid();
		pid = fork();
		if(pid == 0){
			printf(1, "invalid access %x = %x\n", a, *a);
			kill(ppid);
			exit();
		}
		wait();
	}

	printf(1, "OK\n");
	exit();
}
