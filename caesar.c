#include "caesar.h"

#define READ 0
#define WRITE 1
#define LEN 100

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

int parent(char *line, int *rd, int *wr){
  close(rd[WRITE]);
  close(wr[READ]);
  strcpy(line, "");
  while (strcmp(line, "exit")){
    printf("Enter Word to encode (or \"exit\" to quit)\n  ");
    strcpy(line, "");
    fgets(line, LEN, stdin);
    line[strlen(line)-1] = 0;
    if (!strcmp(line, "exit")){
      close(wr[WRITE]);
      close(rd[READ]);
      exit(0);
    }
    write(wr[WRITE], line, LEN);
    read(rd[READ], line, LEN);
    printf("Caesar-Encoded:\n  %s\n\n", line);
  }
}

int child(char *line, int *rd, int *wr){
  close(rd[WRITE]);
  close(wr[READ]);
  while(1){
    read(rd[READ], line, LEN);
    if (!strcmp(line, "exit")){
      close(wr[WRITE]);
      close(rd[READ]);
      exit(0);
    }
    write(wr[WRITE], str_proc(line), LEN);
  }
}

int main(){
  int p2c[2];
  int c2p[2];
  pipe(p2c);
  pipe(c2p);
  char line[LEN];
  int f = fork();
  if (f)
    parent(line, c2p, p2c);
  else
    child(line, p2c, c2p);
  return 0;
}
