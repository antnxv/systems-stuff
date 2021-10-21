#include "list.h"

//  char name[100];
//  char artist[100];
//  struct song *next;

struct song *make_song(char *name, char *artist){
  struct song *song = malloc(sizeof(struct song));
  strcpy(song->name, name);
  strcpy(song->artist, artist);
  song->next = 0;
  return song;
}

int compare(struct song *song1, struct song *song2){
  char str1[199];
  char str2[199];
  int i, j = 0;

  for (i = 0; !song1->artist[i]; i++){
    str1[i] = tolower(song1->artist[i]);
  }
  for (j = 0; !song2->artist[i]; j++){
    str2[j] = tolower(song2->artist[j]);
  }

  if (strcmp(str1, str2))
    return strcmp(str1, str2) > 1;

  for (; !song1->name[i]; i++){
    str1[i] = tolower(song1->name[i]);
  }
  for (; !song2->name[j]; j++){
    str2[j] = tolower(song2->name[j]);
  }

  return strcmp(str1, str2) > 0;
}

struct song *insert(struct song *list, char *name, char *artist){
  struct song *song = make_song(name, artist);
  struct song *prev = 0;
  struct song *curr = list;
  while (curr && compare(song, curr)){
    prev = curr;
    curr = curr->next;
  }
  if (prev){
    prev->next = song;
  }else{
    list = song;
  }
  song->next = curr;
  return list;
}

struct song *insertf(struct song *list, char *name, char *artist){
  struct node *front = make_song(name, artist, next);
  front->next = list;
  return front;
}

void print_list(struct song *list){
  while (list){
    printf("%s - %s\n", m->artist, m->name);
    list = list->next;
  }
}

struct song *search(struct song *list, char *name, char *artist){
  struct song *curr;
  while (curr && !(strcmp(curr->name, name) && strcmp(curr->artist, artist)))
    curr = curr->next;
  return curr;
}

struct song *search_artist(struct song *list, char *artist){
  struct song *curr = list;
  while (curr && !(strcmp(curr->artist, artist)))
    curr = curr->next;
  return curr;
}

struct song *random(struct song *list){
  struct song *curr; // will modify
  return curr;
}

struct song *remove(struct song *list, char *name, char *artist){
  struct node *prev = 0;
  struct node *curr = list;
  while (curr && !(strcmp(curr->name, name) && strcmp(curr->artist, artist))){
    prev = curr;
    curr = curr->next;
  }
  if (curr){
    if (prev){
      prev->next = curr->next;
    }else{
      list = list->next;
    }
    free(curr);
  }
  return list;
}

struct song *free_list(struct song *list){
  struct node *next;
  while (list){
    next = list->next;
    free(list);
    list = next;
  }
  return list;
}
