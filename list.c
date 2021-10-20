#include "list.h"

int compare(struct song *song1, struct song *song2){
  return 0;
}
struct song *insert(struct song *list, struct song *song){
  return list;
}

struct song *insertf(struct song *list, struct song *song){
  return list;
}

void print_list(struct song *list){
  while (list){
    printf("%s - %s\n", m->artist, m->name);
    list = list->next;
  }
}

struct song *search(struct song *list, char *name, char *artist){
  struct song *curr;
  return curr;
}

struct song *search_artist(struct song *list, char *artist){
  struct song *curr;
  return curr;
}

struct song *random(struct song *list){
  struct song *curr; // will modify
  return curr;
}

struct song *remove(struct song *list, char *name, char *artist){
  return list;
}

struct song *free_list(struct song *list){
  return list;
}
