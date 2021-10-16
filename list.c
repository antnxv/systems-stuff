#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct node {char *name; float tall; char unit; struct node *next;};

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

int main(){
  srand(time(NULL));
  
  struct node *jenny;
  char unit = 'c' + (rand()%2)*6;
  jenny = make_node("jenny", ((unit == 'c')? 100+rand()%100 : 39+rand()%40), unit);
  struct node *axel;
  unit = 'c' + (rand()%2)*6;
  axel = insert_front(jenny, "axel", ((unit == 'c')? 100+rand()%100 : 39+rand()%40), unit);
  struct node *mandy;
  unit = 'c' + (rand()%2)*6;
  mandy = insert_front(axel, "mandy", ((unit == 'c')? 100+rand()%100 : 39+rand()%40), unit);

  struct node *m1 = mandy;
  while (m1){
    m1 = swap_unit(m1, (m1->unit == 'c')? 'i' : 'c');
    print_list(m1);

    m1 = swap_unit(m1, (m1->unit == 'c')? 'i' : 'c');
    print_list(m1);

    m1 = m1->next;
  }

  printf("\nFirst node after running free_list: %p\n", free_list(jenny));
  return 0;
}
