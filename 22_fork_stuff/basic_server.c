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
  printf("Running server (don't forget to run this and client in separate tabs)!\n");
  
  int to_client;
  int from_client;

  from_client = server_handshake( &to_client );

  char line[INPLEN];
  while(1){
    read(from_client, line, INPLEN);
    if (!strcmp(line, "exit")){
      close(from_client);
      close(to_client);
      exit(0);
    }
    write(to_client, str_proc(line), INPLEN);
  }
}
