#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct song{
  char name[100];
  char artist[100];
  struct song *next;
};

struct song *make_song(char *name, char *artist);

int compare(struct song *song1, struct song *song2);
struct song *insert(struct song *list, char *name, char *artist);

struct song *insertf(struct song *list, char *name, char *artist);

void print_list(struct song *list);

struct song *search(struct song *list, char *name, char *artist);

struct song *search_artist(struct song *list, char *artist);

struct song *random(struct song *list);

struct song *remove(struct song *list, char *name, char *artist);

struct song *free_list(struct song *list);
