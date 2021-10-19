#include "list.h"

void print_list(struct node *m){
  printf("%s: %f %s tall\n", m->name, m->tall, (m->unit == 'c')? "cm" : "in");
}

struct node *make_node(char *name, float tall, char unit){
  struct node *m = malloc(sizeof(struct node));
  m->name = name;
  m->tall = tall;
  m->unit = unit;
  m->next = NULL;
  return m;
}

// wasn't sure if we should keep the make_node function from 09_construction
//   should be easy to remove
struct node *insert_front(struct node *m1, char *name, float tall, char unit){
  struct node *m2 = make_node(name, tall, unit);
  m2->next = m1;
  return m2;
}

struct node *free_list(struct node *m1){
  struct node *m2;
  while (m1){
    m2 = m1->next;
    free(m1);
    m1 = m2;
  }
  return m1;
}

// assumes nu can only equal "cm" or "in"
struct node *swap_unit(struct node *m, char newnit){
  if (m->unit != newnit){
    if (newnit == 'c'){
      m->tall *= 2.54;
    }else{
      m->tall /= 2.54;
    }
    m->unit = newnit;
  }
  return m;
}
