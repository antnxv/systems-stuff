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

  // 6-8
  unsigned int ui = 2151686160; // 80402010: 2151686160; 16080402010: 1513980174352
  int *uiip = &ui;
  char *uicp = &ui;
  printf("\nuiip: %p uiip points to %d", uiip, *uiip);
  printf("\nuicp: %p uicp points to %c", uicp, *uicp);
  printf("\nui: %u, %x\n", ui, ui);
  

  // 9
  int b;
  printf("hhx:\thhu:\thho:\n");
  for (b = 0; b < 4; b ++){
    printf("%hhx\t%hhu\t%hho\n", *(uicp+b), *(uicp+b), *(uicp+b));
  }

  // 10
  for (b = 0; b < 4; b ++){
    *(uicp+b) += 1;
  }
  printf("\nui: %u, %x\n", ui, ui);
  for (b = 0; b < 4; b ++){
    printf("%hhx\t%hhu\t%hho\n", *(uicp+b), *(uicp+b), *(uicp+b));
  }

  // 11
  for (b = 0; b < 4; b ++){
    *(uicp+b) += 16;
  }
  printf("\nui: %u, %x\n", ui, ui);
  for (b = 0; b < 4; b ++){
    printf("%hhx\t%hhu\t%hho\n", *(uicp+b), *(uicp+b), *(uicp+b));
  }
}
