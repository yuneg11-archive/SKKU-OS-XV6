#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

int main(){
  int i, j, k=0;
  struct pstat pst;
  for(i = 0; i < 300000000; i++){
    k++;
    if(k > 1000)
      k %= 1000;
  }
  printf(1, "%d\n", k);
  if(fork() == 0){
    for(i = 0; i < 2000000000; i++){
      k++;
      if(k > 1000)
        k %= 1000;
    }
    printf(1, "%d\n", k);
    printf(1, "child getpinfo() = %d\n", getpinfo(&pst));
    for(j = 0; j < 9; j++) {
      printf(1, "inuse[%d] = %d, nice[%d] = %d, pid[%d] = %d, ticks[%d] = %d\n", j, pst.inuse[j], j, pst.nice[j], j, pst.pid[j], j, pst.ticks[j]);
    }
    for(i = 0; i < 2000000000; i++){
      k++;
      if(k > 1000)
        k %= 1000;
    }
    printf(1, "%d\n", k);
  } else {
    for(i = 0; i < 2000000000; i++){
      k++;
      if(k > 1000)
        k %= 1000;
    }
    wait();
    printf(1, "%d\n", k);
    printf(1, "parent getpinfo() = %d\n", getpinfo(&pst));
    for(j = 0; j < 9; j++)
      printf(1, "inuse[%d] = %d, nice[%d] = %d, pid[%d] = %d, ticks[%d] = %d\n", j, pst.inuse[j], j, pst.nice[j], j, pst.pid[j], j, pst.ticks[j]);
  }
  
  exit();
}
