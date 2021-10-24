#include "list.h"

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
      return -1;
    else if (tolower(song1->artist[i]) > tolower(song2->artist[i]))
      return 1;
  }

  if (strlen(song1->name) < strlen(song2->name))
    m = strlen(song1->name)+1;
  else
    m = strlen(song2->name)+1;

  for (i = 0; i < m; i++)
    if (tolower(song1->name[i]) < tolower(song2->name[i]))
      return -1;
    else if (tolower(song1->name[i]) > tolower(song2->name[i]))
      return 1;

  return 0;
}

struct song *insert(struct song *list, char *name, char *artist){
  struct song *song = make_song(name, artist);
  struct song *prev = 0;
  struct song *curr = list;
  while (curr && compare(song, curr) > -1){
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

void print_song(struct song *song){
  printf("%s - %s\n", song->artist, song->name);
}

void print_list(struct song *list){
  if (!list)
    return;
  printf("{\n");
  while (list){
    print_song(list);
    list = list->next;
  }
  printf("}\n");
}

struct song *search_song(struct song *list, char *name, char *artist){
  while (list && (strcmp(list->name, name) || strcmp(list->artist, artist)))
    list = list->next;
  return list;
}

struct song *search_artist(struct song *list, char *artist){
  while (list && strcmp(list->artist, artist))
    list = list->next;
  return list;
}

int list_len(struct song *list){
  int i;
  for (i = 0; list; i ++){
    list = list->next;
  }
  return i;
}

struct song *random_song(struct song *list){
  int m = rand() % list_len(list);
  for (;m > 0;m --)
    list = list->next;
  return list;
}

struct song *remove_song(struct song *list, char *name, char *artist){
  struct song *prev = 0;
  struct song *curr = list;
  while (curr && (strcmp(curr->name, name) || strcmp(curr->artist, artist))){
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
