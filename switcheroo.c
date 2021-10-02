#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int readArr(int *a, int s){
  int i;
  printf("{");
  for (i = 0; i < s; i ++){
    printf((i == s-1)? "%d":"%d, ", a[i]);
  }
  printf("}\n");
}

int main(){
  // 1-3
  int i;
  int ray[10];
  ray[0] = 0;
  srand(time(NULL));
  for (i = 1; i < sizeof(ray)/sizeof(ray[0]); i ++){
    ray[i] = rand()%1000;
  }
  readArr(ray, sizeof(ray)/sizeof(ray[0]));
}
