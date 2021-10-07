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

int main() {
  printf("1. %c\n", *mystrchr("hello", 'e'));
  printf("Next 3 are null: %c\n", '\0');
  printf("2. %c\n", *mystrchr("hello", 'a'));
  printf("3. %c\n", *mystrchr("", 's'));
  printf("4. %c\n", *mystrchr("gx", '\0'));
  char s[10] = "hello";
  printf("%p = ", mystrchr(s, 'o'));
  mystrncat(s, "o", 1);
  printf("%p\n", mystrchr(s, 'o'));
}
