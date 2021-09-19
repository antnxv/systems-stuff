#include <stdio.h>

// I feel like I'm probably doing this all wrong but oh well

int argStuff(int argc, char const *argv[]) {
  for (int i = 0; i < argc; i++){
    printf("Argument at index %d is %s%s", i, argv[i], (i == 0)? ", obviously\n" : "\n");
  }
  if (argc == 1){
    printf("No additional arguments passed to %s\n", argv[0]);
  }
  printf("\n");
  return 0;
}

int unsignedStuff() {
  int nums[5] = {0, -2, 2147483647, 2147483648, 4294967295};
  for (int i = 0; i < 5; i ++) {
    printf("(unsigned) (%d+1) == (unsigned) %d == %u\n", nums[i], nums[i]+1, (unsigned int)(nums[i]+1));
    // It is sort of bizarre seeing how readily gcc will let me go out of bounds here
  }

  printf("\n");
  return 0;
}

int main(int argc, char const *argv[]) {
  printf("\n");
  // Optionally comment out the following:
  argStuff(argc, argv);
  unsignedStuff();
}

/*
* I wanted to do something more interesting than this
* but I don't think I can do much until I learn more.
*/
