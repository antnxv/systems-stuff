#include "structy.h"

int main(){
  struct meau *jenny;
  struct meau *axel;
  
  jenny = make_meau("jenny", 170, 'c');
  print_meau(jenny);

  jenny = swap_meau(jenny, 'i');
  print_meau(jenny);
  
  free(jenny);

  printf("\n");
  
  axel = make_meau("axel", 67.5, 'i');
  print_meau(axel);

  axel = swap_meau(axel, 'c');
  print_meau(axel);
  
  free(axel);


  return 0;
}
