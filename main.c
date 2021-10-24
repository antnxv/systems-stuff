#include "librayray.h"

int main(){
  struct song **lib = make_library();
  char kc = 'k';
  char *k = &kc;
  
  printf("\n\n\n####### make_library, make_song, insertl, insert and compare_____\n");
  lib = insertl(lib, "Blood Type", "Kino");
  lib = insertl(lib, "In Our Eyes", "Kino");
  lib = insertl(lib, "False", "Kiwi");
  lib = insertl(lib, "Onward, We'll Proceed", "Kino");
  lib = insertl(lib, "War", "Kino");
  lib = insertl(lib, "O", "K");
  lib = insertl(lib, "Test", "Kinz");
  lib = insertl(lib, "Trial", "Kina");
  lib = insertl(lib, "Blobble", "KinoTest");
  lib = insertl(lib, "Sloth", "Kangaroo");
  lib = insertl(lib, "My Friends", "Kino");
  lib = insertl(lib, "BumboopTest", "Kin");
  lib = insertl(lib, "Tranquiliser", "Kino");
  lib = insertl(lib, "Every Night", "Kino");
  lib = insertl(lib, "Uzbekistan", "Kyrgyzstan");
  lib = insertl(lib, "He Was Older Than Her", "Time Machine");
  lib = insertl(lib, "One Day the World Will Bend Beneath Us", "Time Machine");
  lib = insertl(lib, "People Meet", "Singing Guitars");
  lib = insertl(lib, "Testin", "Setsin");
  lib = insertl(lib, "Crying", ";-;");
  printf("Executed without error\n");
  
  printf("\n\n\n####### insertf (kzzz entries), print_list (k artist index of library) and print_song_____\n");
  lib[lib_index(k)] = insertf(lib[lib_index(k)], "Resting", "Kzzz");
  lib[lib_index(k)] = insertf(lib[lib_index(k)], "Testing", "Kzzz");
  print_list(lib[lib_index(k)]);

  printf("\n\n\n####### print_list on empty list_____:\n");
  struct song *nop = 0;
  print_list(nop);

  printf("\n\n\n####### print_library_____\n");
  print_library(lib);

  printf("\n\n\n####### print_library on empty library_____\n");
  struct song **play = make_library();
  print_library(play);
  
  printf("\n\n\n####### print_artist for Time Machine_____\n");
  print_artist(lib, "Time Machine");

  printf("\n\n\n####### print_letter for S and lib_index_____\n");
  print_letter(lib, (rand() % 2 == 0)? 'S' : 's');

  printf("\n\n\n__print_letter for unused letter_______\n");
  print_letter(lib, 'a');

  printf("\n\n\n####### print_shuffle and list_len_____\n");
  print_shuffle(lib);

  printf("\n\n\n####### random_song and list_len_____\n");
  print_song(random_song(lib[lib_index(k)]));

  printf("\n\n\n####### search_songl and search_song_____\n");
  struct song *s = search_songl(lib, "War", "Kino");
  if (s)
    printf("War = %s\t%p\n", s->name, s);
  else
    printf("Song not found");
  
  
  printf("\n\n\n####### search_songl and search_song on unused song_____\n");
  s = search_songl(lib, "Black Eyes", "Feodor Chaliapin");
  if (s)
    printf("Black Eyes = %s\t%p\n", s->name, s);
  else
    printf("Song not found");

  printf("\n\n\n####### search_artistl and search_artist_____\n");
  s = search_artistl(lib, "Kino");
  if (s)
    printf("Blood Type = %s\t%p\n", s->name, s);
  else
    printf("Artist not found");
  
  
  printf("\n\n\n####### search_artistl and search_artist on unused artist_____\n");
  s = search_artistl(lib, "Feodor Chaliapin");
  if (s)
    printf("Black Eyes = %s\t%p\n", s->name, s);
  else
    printf("Artist not found");

  printf("\n\n\n####### remove_songl and remove_song on Setsin - Testin_____\n");
  lib = remove_songl(lib, "Testin", "Setsin");
  print_letter(lib, 's');
  printf("^^^(Letter s list should no longer contain Setsin)");

  printf("\n\n\n####### remove_songl and remove_song on unused song_____\n");
  lib = remove_songl(lib, "Random", "Words");
  printf("Executed without error");

  printf("\n\n\n####### free_library and free_list_____\n");
  lib = free_library(lib);
  print_library(lib);

  printf("\n\n\n####### free_library and free_list on empty library_____\n");
  play = free_library(play);
  nop = free_list(nop);
}
