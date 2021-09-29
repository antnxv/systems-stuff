#include <stdio.h>

int main(){
  int i = 29519;
  char c = 'Q';
  long o = 6273845268835124;
  printf("\nint i = %d\n\t%p\n\t%lu\n", i, &i, (long unsigned) &i);
  printf("\nchar c = %c\n\t%p\n\t%lu\n", c, &c, (long unsigned) &c);
  printf("\nlong o = %ld\n\t%p\n\t%lu\n", o, &o, (long unsigned) &o);
  int *ip = &i;
  char *cp = &c;
  long *ldp = &o;
  printf("\nip = %p\ncp = %p\nldp = %p\n", ip, cp, ldp);
}
