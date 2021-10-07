#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mystrlen(char *s) {
  int n = 0;
  while (*s != '\0') {
    s ++;
    n ++;
  }
  return n;
}

char * mystrncpy(char *dest, char *source, int n) {
  int i;
  for (i = 0; i < n; i ++) {
    if (source[i] == '\0')
      break;
    dest[i] = source[i];
  }
  for (; i < n; i ++) {
    dest[i] = '\n';
  }
  return dest;
}

int main() {
  char s1[10] = "greetings";
  char s2[10] = "drasti";
  printf("%s\n%s\n", strncpy(s1, s2, 3), mystrncpy(s1, s2, 3));
  printf("%s\n%s\n", strncpy(s1, s2, 8), mystrncpy(s1, s2, 8));
}
