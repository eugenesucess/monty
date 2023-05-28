#include <stdio.h>
#include <stdlib.h>

void read_file(int argc, char **argv)
{
   size_t size;
  char *buffer;
  FILE *fd;
  
  if (argc != 2)
  {
    fprintf(stderr, "few arguments");
    exit(EXIT_FAILURE);
   }
  fd = fopen(argv[1], "r");
  if (fd == NULL)
  {
    fprintf(stderr, "can't open");
    exit(EXIT_FAILURE);
  }
  
  while (getline(&buffer, &size, fd) != -1)
  {
    printf("%s\n", buffer);
  }
  fclose(fd);
  free(buffer);
int main(int argc, char **argv)
{
read_file(argc, argv);
  return 0;
}
