#include "types.h"
#include "stat.h"
#include "user.h"

void *thread(void *arg){
	int tid = gettid();
	int pid = getpid();
	void *retval = (void *)0x87654321;

	printf(1, "Thread tid %d(pid %d) is running, arg=0x%x, retval=0x%x\n", tid, pid, (int)arg, (int)retval);

	thread_exit(retval);
}

int
main(int argc, char **argv)
{
	int tid = gettid();
	int pid = getpid();
	void *stack = malloc(4096);
	void *retval;

	printf(1, "threadtest start\n");

	printf(1, "Main thread: tid %d(pid %d) is running\n", tid, pid);

	tid = thread_create(thread, 20, (void *)0x12345678, stack);
	if(tid == -1){
		printf(1, "thread creation failed\n");
		free(stack);
		exit();
	}

	if(thread_join(tid, &retval) == -1){
		printf(1, "thread %d join failed\n", tid);
		free(stack);
		exit();
	}

	free(stack);
	printf(1, "Thread tid %d is terminated, retval: 0x%x\n", tid, (int)retval);

	exit();
}
