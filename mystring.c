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
/*
int main() {
  char s1[100];
  char s2[100] = "hello";
  printf("comp: %d", mystrcmp(mystrcpy(s1, s2), strcpy(s1, s2)));
  return 0;
}

int main() {

  char s1[100];
  char s2[100] = "hello";
  char s3[100] = "goodbye";

  printf("start strings:\n");
  printf("s1: [%s]\n", s1);
  printf("s2: [%s]\n", s2);
  printf("s3: [%s]\n", s3);

  printf("\nTesting strlen(s2):\n");
  printf("[standard]:\t%lu\n", strlen(s2) );
  printf("[mine]:\t\t%d\n", mystrlen(s2) );

  printf("\nTesting strcpy(s1, s2):\n");
  printf("[standard]:\t[%s]\n", strcpy(s1, s2) );
  printf("[mine]:\t\t[%s]\n", mystrcpy(s1, s2) );
}
*/
