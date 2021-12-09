#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *str_proc(char *line);
// encodes line in caesar cipher (abcdef...z -> xyzabc...w)

int parent(char *line, int *rd, int *wr);
// prompts user for entry (exit exits), writes to wr, waits for child to write to rd, displays line

int child(char *line, int *rd, int *wr);
// waits for parent to write to rd, writes str_proc(line) to wr

int main();
// Initialises pipes, forks and runs parent and child in respective processes
