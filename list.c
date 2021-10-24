#include "list.h"
#include <ctype.h>

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
  int i, m;

  if (strlen(song1->artist) < strlen(song2->artist))
    m = strlen(song1->artist)+1;
  else
     m = strlen(song2->artist)+1;
  
  for (i = 0; i < m; i++){
    if (tolower(song1->artist[i]) < tolower(song2->artist[i]))
      return 0;
    else if (tolower(song1->artist[i]) > tolower(song2->artist[i]))
      return 1;
  }
  
  if (strlen(song1->name) < strlen(song2->name))
    m = strlen(song1->name)+1;
  else
    m = strlen(song2->name)+1;
  
  for (i = 0; i < m; i++)
    if (tolower(song1->name[i]) < tolower(song2->name[i]))
      return 0;
    else if (tolower(song1->name[i]) > tolower(song2->name[i]))
      return 1;
  
  return 1;
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
  struct song *front = make_song(name, artist);
  front->next = list;
  return front;
}

void print_list(struct song *list){
  while (list){
    printf("%s - %s\n", list->artist, list->name);
    list = list->next;
  }
}

struct song *search_song(struct song *list, char *name, char *artist){
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

struct song *random_song(struct song *list){
  struct song *curr; // will modify
  return curr;
}

struct song *remove_song(struct song *list, char *name, char *artist){
  struct song *prev = 0;
  struct song *curr = list;
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
  struct song *next;
  while (list){
    next = list->next;
    free(list);
    list = next;
  }
  return list;
}
