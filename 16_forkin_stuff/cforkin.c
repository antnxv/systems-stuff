#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
  printf("PID: %d\tPPID: %d\t(PAR) (STRTNG)\n", getpid(), getppid());

  if (fork()){
    if (fork()){
      int status;
      int pid = wait(&status);
      printf("PID: %d\tPPID: %d\t(CHI) (EXITED) Slept: %d secs\n",
	     pid, getpid(), WEXITSTATUS(status));
      printf("PID: %d\tPPID: %d\t(PAR) (ENDING)\n",
	     getpid(), getppid());
      return 0;
    }
  }
  printf("PID: %d\tPPID: %d\t(CHI)\n",getpid(), getppid());
  
  srand(getpid());
  int wt = 2 + rand()%4;
  sleep(wt);

  printf("PID: %d\tPPID: %d\t(CHI) (EXITNG) Sleep: %d secs\n",
	 getpid(), getppid(), wt);
  exit(wt);
}
