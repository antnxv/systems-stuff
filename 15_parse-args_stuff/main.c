#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int argcount(char *line){
  int i;
  int c = 1;
  for (i = 0; i < strlen(line); i ++){
    if (line[i] == ' ')
      c ++;
  }
  return c;
}

char **parse_args(char *line){
  int c = argcount(line);
  int i;
  char **argray = malloc(strlen(line));
  for (i = 0; i < c; i ++){
    argray[i] = strsep(&line, " ");
  }
  argray[i] = 0;
  return argray;
}

int main(int argc, char *argv[]){
  char *line;
  if (argc == 1){
    printf("Default test case: \"ls -a -l\":\n");
    strcpy(line, "ls -a -l");
  }else if (argc == 2)
    line = argv[1];
  else{
    printf("Too many arguments, takes one string only\n");
    return -1;
  }
  
  char ** args = parse_args(line);
  execvp(args[0], args);
  free(args);
  return 0;
}
