#include <stdio.h>

int mystrlen(char *s) {
  int n = 0;
  while (*s != '\0') {
    s ++;
    n ++;
  }
  return n;
}

int main(){
  printf("%d is the size of \"hey\"\n", mystrlen("hey"));
  printf("%d is the size of \"\"\n", mystrlen(""));
  printf("%d is the size of \"0\"\n", mystrlen("0"));
  printf("%d is the size of \"\\0\"\n", mystrlen("\\0"));
  // printf("%d is the size of \"\0\"\n", mystrlen("\0")); // error due to null
}
