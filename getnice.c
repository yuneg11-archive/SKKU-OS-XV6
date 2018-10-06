#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char **argv)
{
  if(argc != 2){
    printf(2, "usage: getnice pid...\n");
    exit();
  }

  printf(1, "%d\n", getnice(atoi(argv[1])));
  exit();
}
