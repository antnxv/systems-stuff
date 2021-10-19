#include "list.h"

void print_list(struct node *m){
  while (m){
    printf("%s: %f %s tall\n", m->name, m->tall, (m->unit == 'c')? "cm" : "in");
    m = m->next;
  }
}

// combination of print_list and swap_unit for demonstrative purposes
void print_swap_list(struct node *m){
  while (m){
    printf("%s: %f %s tall\n", m->name, m->tall, (m->unit == 'c')? "cm" : "in");
    swap_unit(m, (m->unit == 'c')? 'i' : 'c');
    printf("%s: %f %s tall\n\n", m->name, m->tall, (m->unit == 'c')? "cm" : "in");
    swap_unit(m, (m->unit == 'c')? 'i' : 'c');
    m = m->next;
  }
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

struct node *remove_node(struct node *m1, int data){
  struct node *prev = 0;
  struct node *curr = m1;
  while (curr && (curr->tall != data)){
    prev = curr;
    curr = curr->next;
  }
  if (curr){
    if (prev){
      prev->next = curr->next;
    }else{
      m1 = m1->next;
    }
    free(curr);
  }
  return m1;
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
