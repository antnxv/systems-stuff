#include "list.h"

int main(){
  struct song *list = 0;
  list = insert(list, "Blood Type", "Kino");
  list = insert(list, "Mama, We've All Gone Mad", "Kino");
  list = insert(list, "In Our Eyes", "Kino");
  list = insert(list, "False", "Kiwi");
  list = insert(list, "Onward, We'll Proceed", "Kino");
  list = insert(list, "War", "Kino");
  list = insert(list, "Test", "Kinz");
  list = insert(list, "Exam", "Kina");
  list = insert(list, "The Slacker", "Kino");
  list = insert(list, "It's Not That Bad", "Kane Strang");
  list = insert(list, "My Friends", "Kino");
  list = insert(list, "Troonkvihlihzator", "Kino");
  list = insert(list, "Every Night", "Kino");
  list = insert(list, "Uzbekistan", "Kyrgiz");
  list = insertf(list, "Resting", "Kzzz");
  list = insertf(list, "Testing", "Kzzz");

  print_list(list);

  printf("Exists: %p", search_song(list, "My Friends", "Kino"));
  printf("Exists: %p", search_artist(list, "Kino"));
  printf("Exists: %p", search_artist(list, "Kyrgiz"));

  while (search_artist(list, "Kino"))
    remove_song(list, search_artist(list, "Kino")->name, "Kino");

  print_list(list);

  free_list(list);
}
