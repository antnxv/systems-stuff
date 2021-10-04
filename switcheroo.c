#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int i;

  // 1
  int size = 10;
  int ray[size];

  // 2
  ray[0] = 0;
  srand(time(NULL));
  for (i = 1; i < size; i ++){
    ray[i] = rand()%1000;
  }
  
  //3
  printf("{");
  for (i = 0; i < size; i ++){
    printf((i == size-1)? "%d":"%d, ", ray[i]);
  }
  printf("}\n");
  
  // 4
  int rra[size];

  // 5
  int *ra = ray;
  int *rr = rra;
  
  // 6
  for (i = 0; i < size; i ++){
    rr[i] = *(ra + size -i -1);
  } //ra[size -(i+1)] ==^^^^^^
  printf("{");
  for (i = 0; i < size; i ++){
    printf((i == size-1)? "%d":"%d, ", *(rr+i));
  }
  printf("}\n");
}
