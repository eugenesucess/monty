#include "monty.h"
#include <stdio.h>
#include <unistd.h>
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
/**
 * is_comment - check if string received is # or not
 * @token: string to check
 * @line_counter: line
 * Return: -1 if sring is not # or 1 if yes
 */
int is_comment(char *token, int line_counter)
{
	if (token == NULL || token[0] == '#')
	{
	line_counter++;
	return (1);
	}
	return (-1);
}
int main(int argc, char **argv)
{
	size_t size;
	char *buffer, *token, *arg;
	FILE *fd;
	unsigned int line_count = 1;
	stack_t *head = NULL;
	fd = fopen(argv[1], "r");
	check_input(argc, argv);
	while (getline(&buffer, &size, fd) != -1)
	{
		token = strtok(buffer, " t\r\n");
		if (strcmp(token, "push") == 0)
		{
			arg = strtok(NULL, " \t\r\n");
			number = atoi(arg);
			push_stack(&head, line_count);
		}
		else
		{
			pall_stack(&head, line_count);
		}
		line_count++;
	}
	fclose(fd);
	free_stack(head);
	return 0;
}
