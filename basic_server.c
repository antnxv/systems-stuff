#include "pipe_networking.h"

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

int main() {
  int sd = server_connect();
  
  char line[INPLEN];
  while(1){
    read(sd, line, INPLEN);
    if (!strcmp(line, "exit")){
      close(sd);
      exit(0);
    }
    write(sd, str_proc(line), INPLEN);
  }
}
