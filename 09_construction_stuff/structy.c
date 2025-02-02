#include "structy.h"

void print_meau(struct meau *m){
  printf("%s is %f %s tall\n", m->n, m->h, (m->u == 'c')? "cm" : "in");
}

struct meau * make_meau(char *n, float h, char u){
  struct meau *m = malloc(sizeof(struct meau));
  m->n = n;
  m->h = h;
  m->u = u;
  return m;
}

// assumes nu can only equal "cm" or "in"
struct meau * swap_meau(struct meau *m, char nu){
  if (m->u != nu){
    if (nu == 'c'){
      m->h *= 2.54;
    }else{
      m->h /= 2.54;
    }
    m->u = nu;
  }
  return m;
}
