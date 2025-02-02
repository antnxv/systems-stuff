#include "control.h"

int main(){
  int semd = semget(SEMKEY, 1, 0644);
  struct sembuf sb;
  sb.sem_num= 0;
  sb.sem_flg = 0;
  sb.sem_op = -1;
  semop(semd, &sb, 1);

  int shmd = shmget(SHMKEY, 1, 0644);
  int *prev_len = shmat(shmd, 0, 0); // later: check to make sure == 0 after ./control -c 
  int file = open(LOG, O_RDWR | O_APPEND, 0644);
  lseek(file, -1 * *prev_len, SEEK_END);
  char *prev = malloc(*prev_len);
  read(file, prev, *prev_len);
  printf("Previous Entry (if such an entry exists):\n\"%s\"\n", prev);
  free(prev);

  char *next = malloc(500);
  printf("Next Entry:\n");
  fgets(next, 500, stdin);
  *prev_len = strlen(next);
  write(file, next, *prev_len);
  free(next);
  
  sb.sem_op = 1;
  semop(semd, &sb, 1);
}
