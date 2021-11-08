#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include "foo.h"

int* count(int ret[2], int arg, int total){
  char b[1];
  if(read(arg,b,1)==1){
  if(b[0]!='\n'){count(ret,arg,total+1);}
  else{
    lseek(arg,-(total+1),SEEK_CUR);
    int a[2];
    ret[0]=total+1;
    ret[1]=1;
    return ret;
  }}else{
    int b[2];
    ret[0]=total+1;
    ret[1]=0;
    return ret;}
}

void run(int fd, struct pop_entry* collection){
  int ans[2];
  int Y;
  int M;
  int BR;
  int Q;
  int BX;
  int SI;
  int copiednum=0;
  int ind=0;
  int* returned=count(ans,fd,0);
  char line[50];
  if(returned[1]){
    read(fd, line, returned[0]);
    printf("copied line = %s",line);
    copiednum=sscanf(line, "%d,%d,%d,%d,%d,%d", &Y, &M, &BR, &Q, &BX, &SI);
    //printf("num elems copied=%d\n",copiednum);
    run(fd, collection);
  }else{
    lseek(fd,-(returned[0]-1),SEEK_END);
    read(fd,line,returned[0]);
    printf("copied line = %s",line);
  }
}











/*
void fill(int fil, struct pop_entry* lib){
  int len;
  int ind=0;
  int chk;
  int Y;
  int M;
  int BR;
  int Q;
  int BX;
  int SI;
  while(count(fil,0)){
    char line[100];
    len=count(fil,0);
    int a =read(fil,line,len);
    printf("%d\n",a);
    lseek(fil,(len),SEEK_CUR);
  }
}
//chk=sscanf(line, "%d,%d,%d,%d,%d,%d",Y,M,BR,Q,BX,SI);
//lib[ind] = (struct pop_entry) { .year=Y , .population=M , .boro="Manhattan" };
//printf("lib[%d]: year=%d\tpopulation=%d\tboro=%s\n",ind,lib[ind].year,lib[ind].population,lib[ind].boro);
//printf("%d\n",chk);
*/
