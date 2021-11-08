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
  int fd2=open("cen.data",O_RDWR | O_CREAT | O_APPEND,0644);
  if(decider==1){
    printf("reading cen.txt\n");
    write(fd2,arr,sizeof(arr));
    printf("wrote %lu bytes to cen.data\n",sizeof(arr));
  }
  if(decider==2){coldisplay(arr);}
  if(decider==3){
    int hold=open("/dev/stdin", O_RDONLY);
    char buffer[100];
    read(hold,buffer,sizeof(buffer));
    int y;
    int p;
    char b[50];
    sscanf(buffer, "%d %s %d", &y, b, &p);
    arr[115] = (struct pop_entry){.year=y, .population=p, *b};
    write(fd2, &arr[115], sizeof(arr[115]));
    printf("Appended data to file: year:%d\tboro=%s\tpop:%d\n",y,b,p);
  }
  if(decider==4){
    coldisplay(arr);
    int index;
    int y2;
    int p2;
    char b2[50];
    int hold2=open("/dev/stdin", O_RDONLY);
    char buffer2[100];
    char buffer3[100];
    read(hold2,buffer2,sizeof(buffer2));
    sscanf(buffer2, "%d", &index);
    read(hold2,buffer3,sizeof(buffer3));
    sscanf(buffer3, "%d %s %d", &y2, b2, &p2);
    arr[index] = (struct pop_entry){.year=y2,.population=p2,*b2};
    write(fd2,arr,sizeof(arr));
    printf("Successfully modified index %d to be %d %s %d\n", index, y2,b2,p2);
  }
  return 0;
}
