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
  int i;
  int n = mystrlen(source);
  for (i = 0; i < n; i ++) {
    dest[i] = source[i];
    if (source[i] == '\0')
      break;
  }
  return dest;
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
  int i;
  for (i = 0; i < n && source[i] != '\0'; i++) {
    dest[size+i] = source[i];
  }
  dest[size+i] = '\0';
  return dest;
}

int mystrcmp(char *s1, char *s2) {
  int i;
  int n = (mystrlen(s1) < mystrlen(s2))? mystrlen(s1) : mystrlen(s2);
  for (i = 0; i < n; i ++) {
    if (s1[i] != s2[i])
      return s1[i] - s2[i];
  }
  return 0;
}

char * mystrchr(char *s, char c) {
  int i = 0;
  while (s[i]){
    if (s[i] == c)
      break;
    i ++;
  }
  return s+i;
}
