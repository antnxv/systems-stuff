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
  int i;
  for (i = 0; i < size; i ++) {
    b[i] = a[i];
  }
  return 0;
}

int main(){ 
  //The following lightly tests all 3 functions:
  int r[0];
  printf("Empty array\n");
  readray(r, 0);
  printf("^Avg: %0.2lf\n\n", avg(r, 0));
  
  int ray[10] = {10, 9, 7, 8, 6, 4, 3, 5, 1, 2};
  readray(ray, 10);
  printf("^Avg: %0.2lf\n\n", avg(ray, 10));

  int a[0];
  printf("Copying from empty to empty\n");
  copy2(r, a, 0);
  readray(a, 0);
  printf("^Avg: %0.2lf\n\n", avg(a, 0));
  
  int arr[10] = {82346342, 8923462, 12364, 286, 1235446, 45867645, 36423426, 457867, 2765347, 0};
  readray(arr, 10);
  printf("^Avg: %0.2lf\n\n", avg(arr, 10));

  copy2(arr, ray, 10);
  printf("After copy (should match above):\n");
  readray(ray, 10);
  printf("^Avg: %0.2lf\n\n", avg(ray, 10));
    
  return 0;
}
