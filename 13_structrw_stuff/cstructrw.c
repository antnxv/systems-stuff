#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>

#define PRINTERR printf("\tERROR %d: %s\n", errno, strerror(errno)); return -1;  

struct pop_entry{
  int year;
  int population;
  char boro[15];
};

int read_csv(){
  int fd1 = open("nyc_pop.csv", O_RDONLY);
  int fd2 = open("nyc_pop.data", O_CREAT | O_RDWR | O_TRUNC, 0666);
  if (fd1 < 0 || fd2 < 0) {PRINTERR}
  char c;
  if (read(fd1, &c, 1) < 0) {PRINTERR}

  char boros[5][15] =
    {"Manhattan",
     "Brooklyn",
     "Queens",
     "Bronx",
     "Staten Island"
    };

  while (c != '\n') // skip line 1
    read(fd1, &c, 1);
  read(fd1, &c, 1);
  while (c != '\n'){ // end of file check
    while (c != '\n'){ // end of line check
      int year = 0;
      while (c != ','){
	year = 10*year + c - 48;
	read(fd1, &c, 1);
      }
      for (int i = 0; i < 5; i ++){
	int pop = 0;
	struct pop_entry ent;

	ent.year = year;
	strcpy(ent.boro, boros[i]);
	read(fd1, &c, 1);

	while (c != ',' && c != '\n'){
	  pop = 10*pop + c - 48;
	  read(fd1, &c, 1);
	}
	ent.population = pop;
	
	if (write(fd2, &ent, sizeof(struct pop_entry)) < 0)
	  {PRINTERR}
      }
      read(fd1, &c, 1);
    }
    read(fd1, &c, 1);
  }
  printf("Successfully reset nyc_pop.data!\n");
  return 0;
}

int read_data(){
  struct stat st;
  stat("nyc_pop.data", &st);
  struct pop_entry *entries = malloc(st.st_size);
  long len_s = sizeof(struct pop_entry);
  
  int fd = open("nyc_pop.data", O_RDONLY);
  if (fd < 0) {PRINTERR}
  if (read(fd, entries, st.st_size) < 0) {PRINTERR}
  int i;
  for (int i = 0; i < st.st_size/len_s; i ++)
    printf("%d)\tYear %d:\t%d\t(%s)\n",
	   i+1, entries[i].year, entries[i].population, entries[i].boro);
  
  free(entries);
  return 0;
}

int parse_int(char *str){
  int i;
  int s = 0;
  for (i = 0; str[i] != '\n'; i ++){
    if (str[i] < '0' || str[i] > '9'){
      printf("Error: Takes a positive int, no punctuation, <15 digits\n");
      return -1;
    }
    s = s*10 + str[i] - 48;
  }
  return s;
}

int add_data(){
  struct pop_entry new;
  char input[15];
  
  printf("Year: ");
  fgets(input, 15, stdin);
  new.year = parse_int(input);
  if (new.year == -1)
    return -1;

  printf("Population: ");
  fgets(input, 15, stdin);
  new.population = parse_int(input);
  if (new.population == -1)
    return -1;

  printf("Borough: ");
  fgets(input, 15, stdin);
  int i;
  for (i = 0; input[i] != '\n'; i ++){}
  input[i] = 0;
  strcpy(new.boro, input);
  
  int fd = open("nyc_pop.data", O_WRONLY | O_APPEND);
  if (fd < 0) {PRINTERR}
  if (write(fd, &new, sizeof(struct pop_entry)) < 0) {PRINTERR}
  printf("Successfully added population data for %d %s!\n", new.year, new.boro);
  return 0;
}

int update_data(){
  read_data();
  int num;
  char input[15];
  printf("Entry Number: ");
  fgets(input, 15, stdin);
  num = parse_int(input);
  if (num == -1)
    return -1;

  struct pop_entry new;
  printf("Year: ");
  fgets(input, 15, stdin);
  new.year = parse_int(input);
  if (new.year == -1)
    return -1;

  printf("Population: ");
  fgets(input, 15, stdin);
  new.population = parse_int(input);
  if (new.population == -1)
    return -1;

  printf("Borough: ");
  fgets(input, 15, stdin);
  int i;
  for (i = 0; input[i] != '\n'; i ++){}
  input[i] = 0;
  strcpy(new.boro, input);

  int fd = open("nyc_pop.data", O_WRONLY);
  if (fd < 0) {PRINTERR}
  if (lseek(fd, (num-1)*sizeof(struct pop_entry), SEEK_SET) < 0) {PRINTERR}
  if (write(fd, &new, sizeof(new)) < 0) {PRINTERR}
  printf("Successfully updated population data for %d %s!\n", new.year, new.boro);
  return 0;
}

int main(int argc, char *argv[]){
  char func[100];
  if (argc > 1)
    strcpy(func,  argv[1]);
  else
    fgets(func, 100, stdin);

  if (!strcmp(func, "-read_csv") || !strcmp(func, "1"))
    return read_csv();
  else if (!strcmp(func, "-read_data") || !strcmp(func, "2"))
    return read_data();
  else if (!strcmp(func, "-add_data") || !strcmp(func, "3"))
    return add_data();
  else if (!strcmp(func, "-update_data") || !strcmp(func, "4"))
    return update_data();
  else
    printf("-read_csv\t-read_data\t-add_data\t-update_data\n");
  return 0;
}
