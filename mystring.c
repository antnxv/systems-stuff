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

char * mystrcpy(char *dest, char *source) {
  int i = 0;
  while (source[i]) {
    dest[i] = source[i];
    i ++;
  }
  dest[i] = source[i];
  return dest;
}

char * mystrncpy(char *dest, char *source, int n) {
  int i = 0;
  while (source[i] && i < n) {
    dest[i] = source[i];
    i ++;
  }
  for (; i < n; i ++) {
    dest[i] = '\0';
  }
  return dest;
}

char * mystrcat(char *dest, char *source) {
  int size = mystrlen(dest);
  int i = 0;
  while (source[i] != '\0') {
    dest[size+i] = source[i];
    i ++;
  }
  dest[size+i] = '\0';
  return dest;
}

char * mystrncat(char *dest, char *source, int n) {
  int size = mystrlen(dest);
  int i = 0;
  while (source[i] != '\0' && i < n) {
    dest[size+i] = source[i];
    i ++;
  }
  dest[size+i] = '\0';
  return dest;
}

int mystrcmp(char *s1, char *s2) {
  int i;
  int n = (strlen(s1) < strlen(s2))? mystrlen(s1) : mystrlen(s2);
  for (i = 0; s1[i] == s2[i] && i < n; i ++);
  return s1[i] - s2[i];
}

char * mystrchr(char *s, char c) {
  int i;
  for (i = 0; s[i] != c; i ++){
    if (s[i] == '\0')
      return (char *)'\0';
  }
  return s+i;
}
