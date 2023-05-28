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

/**
 * is_number - check if string received is int or not
 * @token: string to check
 * Return: -1 if sring is not int or 1 if yes
 */
int is_number(char *token)
{
	int i;

	if (token == NULL)
		return (-1);

	for (i = 0; token[i] != '\0'; i++)
	{
		if (token[i] != '-' && isdigit(token[i]) == 0)
			return (-1);
	}
	return (1);
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
	void (*p_func)(stack_t **, unsigned int);
	size_t size;
	char *buffer, *token, *arg, *command;
	FILE *fd;
	unsigned int line_count = 1;
	stack_t *head = NULL;
	
	fd = fopen(argv[1], "r");
	check_input(argc, argv);
	while (getline(&buffer, &size, fd) != -1)
	{
		token = strtok(buffer, " t\r\n");
		strcpy(command, token);
		if (strcmp(command, "push") == 0)
		{
			arg = strtok(NULL, " \t\r\n");
			token = strtok(NULL, "\n\t\r ");
			if (token == NULL || is_number(token) == -1)
			{
				fprintf(stderr, "unknown instrunctions");
				exit(EXIT_FAILURE);
			}
			
			number = atoi(arg);
			p_func = get_opcode(token, line_count);
			p_func(&head, line_count);
		}
		else
		{
			p_func = get_opcode(command);
			p_func(&head, line_count);
		}
		line_count++;
	}
	fclose(fd);
	free(buffer);
	return 0;
}
