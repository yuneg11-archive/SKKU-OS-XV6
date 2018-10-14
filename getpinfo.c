#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

int main(){
  struct pstat pst;
  int i;

  if(getpinfo(&pst) == 0)
    for(i = 0; i < NPROC; i++)
      printf(1, "inuse[%d] = %d, nice[%d] = %d, pid[%d] = %d, ticks[%d] = %d\n", i, pst.inuse[i], i, pst.nice[i], i, pst.pid[i], i, pst.ticks[i]);

  exit();
}
