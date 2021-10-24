#include "list.h"

int main(){
  srand(time(0)); //temporarily in main
  
  struct song *list = 0;
  list = insert(list, "Blood Type", "Kino");
  list = insert(list, "Mama, We've All Gone Mad", "Kino");
  list = insert(list, "In Our Eyes", "Kino");
  list = insert(list, "False", "Kiwi");
  list = insert(list, "Onward, We'll Proceed", "Kino");
  list = insert(list, "War", "Kino");
  list = insert(list, "O", "K");
  list = insert(list, "Test", "Kinz");
  list = insert(list, "Exam", "Kina");
  list = insert(list, "Blobble", "Kinog");
  list = insert(list, "The Slacker", "Kino");
  list = insert(list, "It's Not That Bad", "Kane Strang");
  list = insert(list, "My Friends", "Kino");
  list = insert(list, "Bumboop", "Kin");
  list = insert(list, "Troonkvihlihzator", "Kino");
  list = insert(list, "Every Night", "Kino");
  list = insert(list, "Uzbekistan", "Kyrgiz");
  list = insertf(list, "Resting", "Kzzz");
  list = insertf(list, "Testing", "Kzzz");

  print_list(list);
  printf("\n");

  struct song *found;

  found = search_song(list, "Not", "Kino");
  printf("%p\t%s = %s\n", found, found->name, "0");

  found = search_song(list, "My Friends", "Kino");
  printf("%p\t%s = %s\n", found, found->name, "My Friends");

  found = search_artist(list, "Kino");
  printf("%p\t%s = %s\n", found, found->name, "Blood Type");

  found = search_artist(list, "Kyrgiz");
  printf("%p\t%s = %s\n", found, found->name, "Uzbekistan");

  printf("\n");
  int z;
  for (z = 0; z < 10; z ++){
    found = random_song(list);
    print_song(found);
  }
  
  printf("\n");
  while (search_artist(list, "Kino"))
    list = remove_song(list, search_artist(list, "Kino")->name, "Kino");
  print_list(list);

  printf("\n");
  list = free_list(list);
  print_list(list);
}
