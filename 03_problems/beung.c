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

/*
 * m = 10: returns 2520;
 * m = 20: returns 232792560
 * It's a bit slow, but the only types of
 * optimisation I can think of require
 * arrays and I'm too scared to delve into
 * those for now.
*/
int allFactors(){ // Problem 5
  int i;
  int m = 20;
  int n = 1;
  int b = 0;
  while (!b){
    for (i = 1; i <= m; i++){
      if (n%i != 0){
        n++;
        b--;
        break;
      }
    }
    b++;
  }
  return n;
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
  printf("Problem 1 Solution: %d\n", multi35());
  printf("Problem 5 Solution: %d\n", allFactors());
  printf("Problem 6 Solution: %d\n", sumSquareDiff());
}
