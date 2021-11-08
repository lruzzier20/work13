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

void run(int fd, struct pop_entry* collection, int ind){
  int ans[2];
  int Y;
  int M;
  int BR;
  int Q;
  int BX;
  int SI;
  int copiednum=0;
  int* returned=count(ans,fd,0);
  char line[100];
  if(returned[1]){
    read(fd, line, returned[0]);
    copiednum=sscanf(line, "%d,%d,%d,%d,%d,%d", &Y, &M, &BR, &Q, &BX, &SI);
    //printf("num elems copied=%d\n",copiednum);

    collection[ind] = (struct pop_entry){.year=Y, .population=M, "Manhattan"};
    ind++;

    collection[ind] = (struct pop_entry){.year=Y, .population=BR, "Brooklyn"};
    ind++;

    collection[ind] = (struct pop_entry){.year=Y, .population=Q, "Queens"};
    ind++;

    collection[ind] = (struct pop_entry){.year=Y, .population=BX, "Bronx"};
    ind++;

    collection[ind] = (struct pop_entry){.year=Y, .population=SI, "Staten Island"};
    ind++;

    run(fd, collection, ind);
  }else{
    lseek(fd,-(returned[0]-1),SEEK_END);
    read(fd,line,returned[0]);
    copiednum=sscanf(line, "%d,%d,%d,%d,%d,%d", &Y, &M, &BR, &Q, &BX, &SI);
    //printf("num elems copied=%d\n",copiednum);

    collection[ind] = (struct pop_entry){.year=Y, .population=M, "Manhattan"};
    ind++;

    collection[ind] = (struct pop_entry){.year=Y, .population=BR, "Brooklyn"};
    ind++;

    collection[ind] = (struct pop_entry){.year=Y, .population=Q, "Queens"};
    ind++;

    collection[ind] = (struct pop_entry){.year=Y, .population=BX, "Bronx"};
    ind++;

    collection[ind] = (struct pop_entry){.year=Y, .population=SI, "Staten Island"};
    ind++;

  }
}

void coldisplay(struct pop_entry* lib){
  int i=0;
  while(i<115){
    printf("%d: Year: %d\tBorough: %s\tPopulation: %d\n",i,lib[i].year,lib[i].boro,lib[i].population);
    i++;
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
