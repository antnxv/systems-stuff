#include "structy.h"
#include <time.h>

int main(){
  struct meau *jenny;
  srand(time(NULL));
  
  jenny = make_meau("jenny", rand()%200, 'c'+(rand()%2)*6);

  jenny = swap_meau(jenny, (jenny->u == 'c')? 'i' : 'c');
  print_meau(jenny);
  
  jenny = swap_meau(jenny, (jenny->u == 'c')? 'i' : 'c');
  print_meau(jenny);
  
  free(jenny);


  return 0;
}
