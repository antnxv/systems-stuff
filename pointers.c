#include <stdio.h>

int main(){

  // 1-2
  int i = 2;
  char c = 'Q';
  long o = 6273845268835124;
  printf("\nint i = %d\n\t%p\n\t%lu\n", i, &i, (long unsigned) &i);
  printf("\nchar c = %c\n\t%p\n\t%lu\n", c, &c, (long unsigned) &c);
  printf("\nlong o = %ld\n\t%p\n\t%lu\n", o, &o, (long unsigned) &o);

  // 3-4
  int *ip = &i;
  char *cp = &c;
  long *ldp = &o;
  printf("\nip = %p\ncp = %p\nldp = %p\n", ip, cp, ldp);

  // 5
  *ip -= 2;
  *cp += 2;
  *ldp -= 24;
  printf("\nint i = %d\nchar c = %c\nlong o = %ld\n", *ip, *cp, *ldp);
}
