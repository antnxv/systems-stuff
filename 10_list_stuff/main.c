#include "list.h"

int main(){
  srand(time(NULL));

  struct node *folks = 0;
  char names[5][10] = {"jenny", "axel", "mandy", "niko", "maple"};
  int torem[5];
  int t = 0;
  int i;
  for (i = 0; i < 5; i ++){
    char unit = 'c' + (rand() % 2) * 6; // randomises unit between 'c' and 'i'
    int tall = (unit == 'c')? 100 + rand() % 100 : 39 + rand() % 40; // randomises height
    if (rand()%2 == 0){ // randomises which units are removed
      torem[t] = tall;
      t ++;
    }
    folks = insert_front(folks, names[i], tall, unit);
  }
  print_swap_list(folks);

  // Note: this is susceptible to floating point errors :(
  printf("\nRemoving:\n");
  for (i = 0; i < t; i ++){
    printf("%d\n", torem[i]);
    folks = remove_node(folks, torem[i]);
  }
  printf("\n");
  print_list(folks); // less elaborate than print_swap_list, no conversions
  
  printf("\nFirst node after running free_list: %p\n", free_list(folks));
  
  return 0;
}
