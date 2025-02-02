#include "pipe_networking.h"

int main() {
  int sd = client_connect();
  
  char line[INPLEN];
  strcpy(line, "");
  while (strcmp(line, "exit")){
    printf("Enter phrase to encode (or \"exit\" to quit)\n  ");
    strcpy(line, "");
    fgets(line, INPLEN, stdin);
    line[strlen(line)-1] = 0;
    if (!strcmp(line, "exit")){
      close(sd);
      exit(0);
    }
    write(sd, line, INPLEN);
    read(sd, line, INPLEN);
    printf("Caesar-Encoded:\n  %s\n\n", line);
  }
  return 0;
}
