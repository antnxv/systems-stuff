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
 * m = 10: returns 2520
 * m = 20: returns 232792560
*/
long allFactors(){ // Problem 5
  int i, j;
  int m = 20;
  long n1 = 1;
  long n2 = 1;
  int f = 0;
  for (i = 1; i <= m; i++){
    j = i;
    n2 = n1;
    for (f = 2; j > 1; f ++){
      if (j % f == 0){
	if (n2 % f != 0){
	  n1 *= f;
	  n2 *= f;
	}
	n2 /= f;
	j /= f;
	f--;
      }
    }
  }
  return n1;
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
