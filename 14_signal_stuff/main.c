#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

static void inthandler(int signo){
  int fd = open("exitlog.txt", O_CREAT | O_WRONLY | O_APPEND, 0666);
  if (fd < 0){
    printf("ERROR %d: %s\n", errno, strerror(errno));
    exit(-1);
  }
  
  char log[100];
  time_t curtime;
  time(&curtime);
  strcpy(log, ctime(&curtime));
  strcat(log, "   - Exited in response to SIGINT signal\n");

  if (write(fd, log, strlen(log)) < 0){
    printf("ERROR %d: %s\n", errno, strerror(errno));
    exit(-1);
  }
  exit(0);
}

static void usr1handler(int signo){
  printf("PPID: %d\n", getppid());
}

int main(){
  signal(SIGINT, inthandler);
  signal(SIGUSR1, usr1handler);
  
  while (1){
    printf("PID: %d\n", getpid());
    sleep(1);
  }
}
