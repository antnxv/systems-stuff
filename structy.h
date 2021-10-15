#include <stdio.h>

struct meau {char *n; int h; char *u;};

void print_meau(struct meau *m);
struct meau * make_meau(char *n, int h, char *u);
struct meau * swap_meau(struct meau *m);
