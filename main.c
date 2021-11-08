#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include "foo.h"
#include <errno.h>
int main(int argc, char* argv[]){
  int decider=0;
  if(argc>1){decider=-1;}
  if(decider&&!strcmp(argv[1],"-read_csv")){decider=1;}
  if(decider&&!strcmp(argv[1],"-read_data")){decider=2;}
  if(decider&&!strcmp(argv[1],"-add_data")){decider=3;}
  if(decider&&!strcmp(argv[1],"-update_data")){decider=4;}

  struct pop_entry arr[200];
  int fil=open("cen.txt", O_RDWR);
  int ab[2];
  lseek(fil, count(ab,fil,0)[0], SEEK_SET);
  run(fil, arr, 0);
  if(decider==1){
    printf("reading cen.txt\n");
    int fd2=open("cen.data",O_RDWR | O_CREAT,0644);
    write(fd2,arr,sizeof(arr));
    printf("wrote %lu bytes to cen.data\n",sizeof(arr));
  }
  if(decider==2){coldisplay(arr);}
  return 0;
}
