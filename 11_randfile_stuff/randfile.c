#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define SIZE 10

int generand(int b){
  int *n;
  int fd = open("/dev/urandom", O_RDONLY);

  if (fd < 0){
    printf("\t%d:\n%s\n", errno, strerror(errno));
    return errno;
  }

  if (read(fd, n, b) < 0){
    printf("\t%d:\n%s\n", errno, strerror(errno));
    return errno;
  }
  
  return *n;
}

int main(){
  int i;
  int nums[SIZE];
  printf("\nRandom Array:\n{\n");
  for (i = 0; i < SIZE; i ++){
    nums[i] = generand(sizeof(int));
    printf("\t%d\n", nums[i]);
  }
  printf("}\n");

  
  printf("\nCreating new file...\n");
  int fd1 = open("rayndom.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
  if (fd1 < 0){
    printf("\tERROR: %d: %s\n", errno, strerror(errno));
    return errno;
  }else{
    printf("\tSuccess! rayndom.txt exists!\n");
  }

  
  printf("\nWriting to file...\n");
  int q = write(fd1, nums, SIZE*sizeof(int));
  if (q < 0){
    printf("\tERROR: %d: %s\n", errno, strerror(errno));
    return errno;
  }else{
    printf("\tSuccess! Wrote %d bytes!\n", q);
  }

  
  printf("\nReading from file...\n");
  int noms[SIZE] = {}; // 0s for debugging purposes
  int fd2 = open("rayndom.txt", O_RDONLY);
  q = read(fd2, noms, sizeof(noms));
  if (q < 0){
    printf("\t%d:\n%s\n", errno, strerror(errno));
    return errno;
  }else{
    printf("\tSuccess! Read %d bytes!\n", q);
  }

  printf("\nDuplicate Array:\n{\n");
  for (i = 0; i < SIZE; i ++)
    printf("\t%d\n", noms[i]);
  printf("}\n");


  // comparison for convenience:
  for (i = 0; i < SIZE; i ++){
    if (nums[i] != noms[i]){
      printf("\nERROR! Arrays do not match at %d!\t%d != %d\n\n", i, nums[i], noms[i]);
      return -1;
    }
  }
  printf("\nSuccess! Arrays match!\n\n");
  
  return 0;
}
