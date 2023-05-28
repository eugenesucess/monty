#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int number;
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
	unsigned int line_count = 1;
	stack_t **head = NULL;
	
	fd = fopen(argv[1], "r");
	check_input(argc, argv);
	while (getline(&buffer, &size, fd) != -1)
	{
		token = strtok(buffer, " t\r\n");
		
		if (strcmp(token, "push") == 0)
		{
			arg = strtok(NULL, " \t\r\n");
			number = atoi(arg);
			push_stack(head, line_count);
		}
		else
		{
			pall_stack(head, line_count);
		}
		line_count++;
	}
	fclose(fd);
	free(buffer);
	return 0;
}
