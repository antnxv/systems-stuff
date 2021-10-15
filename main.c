#include "structy.h"

int main(){
  struct meau jenny;
  jenny.n = "jenny";
  jenny.h = 170;
  jenny.u = "cm";
  print_meau(&jenny);
  return 0;
}
