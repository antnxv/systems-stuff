#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

struct size{long s; char p;};

int prefix(long unsigned s){
  if (s > 1000000000){
    return 'G';
  }else if (s > 1000000){
    return 'M';
  }else if (s > 1000){
    return 'K';
  }
  return 0;
}

char *path(char *dir, char *pa, char *name){
  strcpy(pa, dir);
  strcat(pa, name);
  return pa;
}

long unsigned size(char *pa, DIR *d, char *dir){
  int s, si = 0;
  struct dirent *ent;
  struct stat st;

  while (ent = readdir(d)){
    if (stat(path(dir, pa, ent->d_name), &st) < 0){
      printf("Error %d: %s\n", errno, strerror(errno));
      printf("\tFaulty Path: %s\n", pa);
    }
    s += st.st_size;
  }

  rewinddir(d);
  return s;
}

int printdir(DIR *d, char *dir){
  struct dirent *ent;
  struct stat st;

  while (ent = readdir(d)){
    if (ent->d_type == DT_DIR){
      char pa[strlen(dir)];
      if (stat(path(dir, pa, ent->d_name), &st) < 0){
	printf("Error %d: %s\n", errno, strerror(errno));
	printf("\tFaulty Path: %s\n", pa);
	return -1;
      }
      long unsigned s = st.st_size;
      char p = prefix(s);
      switch (p){
      case 'G': s /= 1000;
      case 'M': s /= 1000;
      case 'K': s /= 1000;
      }
      printf("Dir:\t%07o\t%lu %cB\t%s\n", st.st_mode, s, p, ent->d_name);
    }
  }

  rewinddir(d);
  return 0;
}

int printfil(DIR *d, char *dir){
  struct dirent *ent;
  struct stat st;

  while (ent = readdir(d)){
    if (ent->d_type != DT_DIR){
      char pa[strlen(dir)];
      if (stat(path(dir, pa, ent->d_name), &st) < 0){
	printf("Error %d: %s\n", errno, strerror(errno));
	printf("\tFaulty Path: %s\n", pa);
	return -1;
      }
      long unsigned s = st.st_size;
      char p = prefix(s);
      switch (p){
      case 'G': s /= 1000;
      case 'M': s /= 1000;
      case 'K': s /= 1000;
      }
      printf("File:\t%07o\t%lu %cB\t%s\n", st.st_mode, s, p, ent->d_name);
    }
  }

  rewinddir(d);
  return 0;
}

int main(int argc, char *argv[]){
  if (argc == 1){
    printf("Enter a directory to scan\n");
    return -1;
  }
  
  int i;
  char dir[strlen(argv[1])+1];
  strcpy(dir, argv[1]);
  if (dir[strlen(dir)-1] != '/')
    strcat(dir, "/");
  
  DIR *d;
  d = opendir(dir);
  if (d == 0){
    printf("Error %d: %s\n", errno, strerror(errno));
    return -1;
  }
  
  char pa[strlen(dir)+101];
  long unsigned s = size(pa, d, dir);
  
  char p = prefix(s);
  switch (p){
  case 'G': s /= 1000;
  case 'M': s /= 1000;
  case 'K': s /= 1000;
  }

  printf("Total Directory Size: %lu %cB\n", s, p);
  printdir(d, dir);
  printfil(d, dir);

  closedir(d);
  return 0;
}
