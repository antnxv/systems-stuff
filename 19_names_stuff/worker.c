#include "caesar.h"

char *str_proc(char *line){
  int i;
  for (i = 0; i < strlen(line); i++){
    if ((line[i] >= 'A' && line[i] <= 'Z') ||
        (line[i] >= 'a' && line[i] <= 'z')){
      if (line[i] <= 'C' ||
          (line[i]>= 'a' && line[i] <= 'c'))
        line[i] += 23;
      else
        line[i] -= 3;
    }
  }
  return line;
}

int main(){
  printf("Running worker (don't forget to run this and interface in separate tabs)!\n");
  int rd, wr;
  char line[LEN];
  rd = open("i2w", O_RDONLY);
  wr = open("w2i", O_WRONLY);
  
  while(1){
    read(rd, line, LEN);
    if (!strcmp(line, "exit")){
      close(rd);
      close(wr);
      exit(0);
    }
    write(wr, str_proc(line), LEN);
  }
}
