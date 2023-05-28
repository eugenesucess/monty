#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_input(int argc, char **argv)
{  
	FILE *fd;
	fd = fopen(argv[1], "r");
	if (argc != 2)
	{
		fprintf(stderr, "few arguments");
		exit(EXIT_FAILURE);
	}
	if (fd == NULL)
	{
		fprintf(stderr, "can't open");
		exit(EXIT_FAILURE);
	}

}
int main(int argc, char **argv)
{
	size_t size;
	char *buffer, *token, *arg;
	FILE *fd;
	fd = fopen(argv[1], "r");
	check_input(argc, argv);
	while (getline(&buffer, &size, fd) != -1)
	{
		token = strtok(buffer, " t\r\n");
		
		if (strcmp(token, "push") == 0)
		{
			printf("I\'m going to push\n");
			arg = strtok(NULL, " \t\r\n");
			printf("my arg is %s\n", arg);
		}
		else
		{
			printf("Its not push\n");
		}
	printf("%s\n", buffer);
	}
	fclose(fd);
	free(buffer);
	return 0;
}
