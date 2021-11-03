#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

struct size{long s; char p;};

long unsigned size(DIR *d){
  int s, si = 0;
  struct dirent *ent;
  struct stat st;
  
  while (ent = readdir(d)){
    if (stat(ent->d_name, &st)){
      printf("Error %d: %s\n", errno, strerror(errno));
    }
    s += st.st_size;
  }
  
  rewinddir(d);
  return s;
}

int prefix(long unsigned s){
  if (s > 1000000000){
    return 'G';
  }else if (s > 1000000){
    return 'M';
  }else if(s > 1000){
    return 'K';
  }
  return 0;
}

int printdir(DIR *d){
  struct dirent *ent;
  struct stat st;

  while (ent = readdir(d)){
    if (ent->d_type == DT_DIR){
      stat(ent->d_name, &st);
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

int printfil(DIR *d){
  struct dirent *ent;
  struct stat st;

  while (ent = readdir(d)){
    if (ent->d_type != DT_DIR){
      stat(ent->d_name, &st);
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

int main(){
  DIR *d;
  d = opendir(".");

  if (d < 0){
    printf("Error %d: %s\n", errno, strerror(errno));
  }

  long unsigned s = size(d);
  char p = prefix(s);
  switch (p){
  case 'G': s /= 1000;
  case 'M': s /= 1000;
  case 'K': s /= 1000;
  }

  printf("Total Directory Size: %lu %cB\n", s, p);
  printdir(d);
  printfil(d);
  
  closedir(d);
}
