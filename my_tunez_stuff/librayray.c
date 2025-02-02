#include "librayray.h"


struct song **make_library(){
  srand(time(0));
  struct song **lib = malloc(27 * sizeof(struct song *));
  int i;
  for (i = 0; i < 27; i ++){
    lib[i] = 0;
  }
  return lib;
}

int lib_index(char *artist){
  if (tolower(artist[0]) == toupper(artist[0]))
    return 26;
  return toupper(artist[0])-65;
}

struct song **insertl(struct song **lib, char *name, char *artist){
  lib[lib_index(artist)] = insert(lib[lib_index(artist)], name, artist);
  return lib;
}

struct song *search_songl(struct song **lib, char *name, char *artist){
  return search_song(lib[lib_index(artist)], name, artist);
}

struct song *search_artistl(struct song **lib, char *artist){
  return search_artist(lib[lib_index(artist)], artist);
}

void print_letter(struct song **lib, char letter){
  print_list(lib[lib_index(&letter)]);
}

void print_artist(struct song **lib, char *artist){
  struct song *list = lib[lib_index(artist)];
  while (list){
    if (!strcmp(list->artist, artist))
      print_song(list);
    list = list->next;
  }
}

void print_library(struct song **lib){
  int i;
  printf("{\n");
  struct song *curr;
  for (i = 0; i < 27; i ++){
    curr = lib[i];
    while (curr){
      print_song(curr);
      curr = curr->next;
    }
  }
  printf("}\n");
}

void print_shuffle(struct song **lib){
  int n;
  for (n = 0; n < 7; n ++){
    int i;
    int j, m = 0;
    for (i = 0; i < 27; i ++){
      m += list_len(lib[i]);
    }
    m = rand() % m;
    i = 0;
    struct song *curr = lib[0];
    while (m > 0 || !curr){
      if (curr){
	curr = curr->next;
	m--;
      }else{
	i ++;
	curr = lib[i];	
      }
    }
    print_song(curr);
  }
}

struct song **remove_songl(struct song **lib, char *name, char *artist){
  lib[lib_index(artist)] = remove_song(lib[lib_index(artist)], name, artist);
  return lib;
}

struct song **free_library(struct song **lib){
  int i;
  for (i = 0; i < 27; i ++){
    lib[i] = free_list(lib[i]);
  }
  return lib;
}
