#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>


unsigned long size(DIR *d){
  int su, si = 0;
  struct dirent *ent;
  struct stat st;
  
  while (ent = readdir(d)){
    if (stat(ent->d_name, &st)){
      printf("Error %d: %s\n", errno, strerror(errno));
    }
    su += st.st_size;
  }
  
  rewinddir(d);
  return su;
}

int printdir(DIR *d){
  struct dirent *ent;
  struct stat st;

  while (ent = readdir(d)){
    if (ent->d_type == DT_DIR){
      stat(ent->d_name, &st);
      printf("Dir:\t%o\t%lu bytes\t%s\n", st.st_mode, st.st_size, ent->d_name);
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
      printf("File:\t%o\t%lu bytes\t%s\n", st.st_mode, st.st_size, ent->d_name);
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
  
  printf("Total Directory Size: %lu bytes\n", size(d));
  printdir(d);
  printfil(d);
  
  closedir(d);
}
