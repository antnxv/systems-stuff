#include <stdio.h>

int readray(int *ray, int size) {
  int i;
  printf("[ ");
  for (i = 0; i < size; i ++){
    printf("%d ", ray[i]);
  }
  printf("]\n");
  return 0;
}

double avg(int *ray, int size) {
  int i;
  double a;
  for (i = 0; i < size; i ++){
    a += ray[i];
  }
  return a / size;
}

int copy2(int *a, int *b, int size){
  return 0;
}

int main(){
  int ray[0] = {};
  readray(ray, 0);
  printf("^Avg: %0.2lf\n\n", avg(ray, 0));
  
  int rra[1] = {1};
  readray(rra, 1);
  printf("^Avg: %0.2lf\n\n", avg(rra, 1));
	 
  int arr[10] = {82346342, 8923462, 12364, 286, 1235446, 45867645, 36423426, 457867, 2765347, 0};
  readray(arr, 10);
  printf("^Avg: %0.2lf\n\n", avg(arr, 10));
  return 0;
}
