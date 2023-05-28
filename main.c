#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  size_t size;
  char **buffer;
  FILE *fd;
  
  fd = fopen(argv[1], "r");
  while (getline(&buffer, &size, fd) != -1)
  {
    printf("%s\n", buffer);
  }
  return 0;
}
