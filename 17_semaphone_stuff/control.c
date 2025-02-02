#include "control.h"

int cre(int shmd, int semd, int file){
  shmd = shmget(SHMKEY, sizeof(int), IPC_CREAT | 0644);
  semd = semget(SEMKEY, 1, IPC_CREAT | 0644);
  union semun us;
  us.val = 1;
  semctl(semd, 0, SETVAL, us);

  file = open(LOG, O_CREAT | O_WRONLY | O_TRUNC, 0644);
  close(file);
  return 0;
}

int rem(int shmd, int semd, int file){
  semd = semget(SEMKEY, 0, 0);
  shmd = shmget(SHMKEY, 0, 0);
  shmctl(shmd, IPC_RMID, 0);
  semctl(semd, 0, IPC_RMID);

  struct stat st;
  stat(LOG, &st);
  char *log_txt = malloc(st.st_size);
  file = open(LOG, O_RDONLY, 0644);
  read(file, log_txt, st.st_size);
  close(file);
  
  printf("Final Result:\n{\n%s}\n", log_txt);
  free(log_txt);
  return 0;
}

int main(int argc, char *argv[]){
  int shmd = 0;
  int semd = 0;
  int file = 0;

  if (argv[1] && (!strcmp(argv[1], "create") || !strcmp(argv[1], "-c")))
    return cre(shmd, semd, file);
  else if (argv[1] && (!strcmp(argv[1], "remove") || !strcmp(argv[1], "-r")))
    return rem(shmd, semd, file);
  printf("Invalid Input; Accepts \"create\"/\"-c\" or \"remove\"/\"-r\"\n");
  return -1;
}
