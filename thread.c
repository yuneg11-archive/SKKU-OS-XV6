#include "types.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "x86.h"
#include "proc.h"
#include "spinlock.h"

int thread_create(void *(*function)(void *), int priority, void *arg, void *stack){
	return -1;
}

void thread_exit(void *retval){
}

int thread_join(int tid, void **retval){
	return -1;
}

int gettid(void){
	return -1;
}
