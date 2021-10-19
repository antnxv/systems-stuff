#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct node {char *name; float tall; char unit; struct node *next;};

void print_list(struct node *m);
void print_swap_list(struct node *m);
struct node *make_node(char *name, float tall, char unit);
struct node *insert_front(struct node *m1, char *name, float tall, char unit);
struct node *remove_node(struct node *m1, int data);
struct node *free_list(struct node *m1);
struct node *swap_unit(struct node *m, char newnit);
