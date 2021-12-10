#include "caesar.h"

int main(){
  int rd, wr;
  char line[LEN];
  printf("Running interface (don't forget to run this and worker in separate tabs)!\n");
  mkfifo("i2w", 0644);
  wr = open("i2w", O_WRONLY);
  mkfifo("w2i", 0644);
  rd = open("w2i", O_RDONLY);
  
  strcpy(line, "");
  while (strcmp(line, "exit")){
    printf("Enter phrase to encode (or \"exit\" to quit)\n  ");
    strcpy(line, "");
    fgets(line, LEN, stdin);
    line[strlen(line)-1] = 0;
    if (!strcmp(line, "exit")){
      close(rd);
      close(wr);
      exit(0);
    }
    write(wr, line, LEN);
    read(rd, line, LEN);
    printf("Caesar-Encoded:\n  %s\n\n", line);
  }
  return 0;
}
