#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include "foo.h"

int main(int argc, char* argv[]){
  int decider=0;
  if(argc>1){decider=-1;}
  if(decider&&!strcmp(argv[1],"-read_csv")){decider=1;}
  if(decider&&!strcmp(argv[1],"-read_data")){decider=2;}
  if(decider&&!strcmp(argv[1],"-add_data")){decider=3;}
  if(decider&&!strcmp(argv[1],"-update_data")){decider=4;}

  struct pop_entry arr[100];
  int fil=open("cen.txt", O_RDWR);
  int ab[2];
  lseek(fil, count(ab,fil,0)[0], SEEK_SET);
  run(fil, arr);
  printf("\n");
  return 0;
}
