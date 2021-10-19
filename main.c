#include "list.h"

int main(){
  srand(time(NULL));

  struct node *folks = 0;
  char names[5][10] = {"jenny", "axel", "mandy", "niko", "maple"};
  int i;
  
  for (i = 0; i < 5; i ++){
    char unit = 'c' + (rand() % 2) * 6; // randomises unit between 'c' and 'i'
    int tall = (unit == 'c')? 100 + rand() % 100 : 39 + rand() % 40; // randomises height
    folks = insert_front(folks, names[i], tall, unit);
  }
  
  //print_list(folks); // lame version
  print_swap_list(folks); // cool version

  printf("\nFirst node after running free_list: %p\n", free_list(folks));
  return 0;
}
