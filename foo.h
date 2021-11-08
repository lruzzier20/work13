struct pop_entry{
  int year;
  int population;
  char boro[15];
};

int* count(int ret[2],int arg, int total);
//void fill(int fil, struct pop_entry* lib);
void run(int fd, struct pop_entry* collection, int ind);
void coldisplay(struct pop_entry* lib);
