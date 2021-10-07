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

char * mystrncat(char *dest, char *source, int n) {
  int size = mystrlen(dest);
  int i; // I didn't know conditionals like this could be used in for statments!
  for (i = 0; i < n && source[i] != '\0'; i++) {
    dest[size+i] = source[i];
  }
  dest[size+i] = '\0';
  return dest;
}

int mystrcmp(char *s1, char *s2) {
  int i; // the following is probably inefficient but it's an interesting way to do it, i guess
  int n = (mystrlen(s1) < mystrlen(s2))? mystrlen(s1) : mystrlen(s2);
  for (i = 0; i < n; i ++) {
    if (s1[i] != s2[i])
      return s1[i] - s2[i];
  }
  return 0;
}

int main() {
  // I did a lot of testing that was extremely and shamefully ugly
}
