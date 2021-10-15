#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct meau {char *n; float h; char u;};

void print_meau(struct meau *m);
struct meau * make_meau(char *n, float h, char u);
struct meau * swap_meau(struct meau *m, char nu);
