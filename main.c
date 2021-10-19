#include "list.h"

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
