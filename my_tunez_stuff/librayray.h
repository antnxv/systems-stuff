#include "list.h"

struct song **make_library();

int lib_index(char *artist);

struct song **insertl(struct song **lib, char *name, char *artist);

struct song *search_songl(struct song **lib, char *name, char *artist);

struct song *search_artistl(struct song **lib, char *artist);

void print_letter(struct song **lib, char letter);

void print_artist(struct song **lib, char *artist);

void print_library(struct song **lib);

void print_shuffle(struct song **lib);

struct song **remove_songl(struct song **lib, char *name, char *artist);

struct song **free_library(struct song **lib);
