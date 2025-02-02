#include "pipe_networking.h"

int main() {
  printf("Running server (don't forget to run this and client in separate tabs)!\n");
  
  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );

  char line[INPLEN];
  strcpy(line, "");
  while (strcmp(line, "exit")){
    printf("Enter phrase to encode (or \"exit\" to quit)\n  ");
    strcpy(line, "");
    fgets(line, INPLEN, stdin);
    line[strlen(line)-1] = 0;
    if (!strcmp(line, "exit")){
      close(from_server);
      close(to_server);
      exit(0);
    }
    write(to_server, line, INPLEN);
    read(from_server, line, INPLEN);
    printf("Caesar-Encoded:\n  %s\n\n", line);
  }
  return 0;
}
