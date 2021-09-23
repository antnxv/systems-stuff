#include <stdio.h>

int multi35(){ // Problem 1
  int i = 1000;
  int s = 0;
  while (i > 3){
    i --;
    if (i % 3 == 0 || i % 5 == 0){
      s += i;
    }
  }
  return s;
}

int sumSquareDiff(){ // Problem 6
  int uq = 0;
  int qu = 0;
  int i;
  for (i = 1; i <= 100; i++){
    uq += i*i;
    qu += i;
  }
  return qu*qu - uq;
}

int main(){

}
