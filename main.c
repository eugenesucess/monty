#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

FILE *check_file(int argc, char **argv)
{
	FILE *fd;
	
	if (argc != 2)
	{
		fprintf(stderr, "few arg");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "can't open file");
		exit(EXIT_FAILURE);
	}
	printf("file");
	return (fd);
/*void check_open_file(char **argv)
{
	void (*f)(stack_t **, unsigned int);
	FILE *fd;
	char *buffer = NULL, *parsed = NULL, command[1024];
	size_t len = 0;
	ssize_t len_size;
	unsigned int line_count = 1;
	stack_t *top = NULL;
	
	fd = fopen(argv[1], "r");
	if (fd = NULL)
	{
		fprintf(stderr, "can't open file'");
		exit(EXIT_FAILURE);
	}
	
	while((len_size = getline(&buffer, &len, fd)) != EOF)
	{
		/*parsed = strtok(buffer, " \t\r\n");
		if (*parsed == '\0')
			continue;
		strcpy(command, parsed);
		
		if (parsed == NULL || parsed[0] == '#')
			exit(EXIT_FAILURE);
		if (strcmp(parsed, "push") == 0)
		{
			parsed = strtok(NULL, "\t\r\n");
			
			if (parsed == NULL || is_number(parsed) == -1)
			{
				fprintf(stderr, "not an intger");
				exit(EXIT_FAILURE);
			}
			
			number = atoi(parsed);
			
			f = get_opcode(command);
			f(&top, line_count);
		
		}
		else
		{
			f = get_opcode(command);
			f(&top, line_count);
		}
		line_count++;
	}
	fclose(fd);
	free(buffer);
	free(top);
}
*/
int main(int argc, char **argv) {
	FILE *fd;
	fd = check_file(argc, argv);
	read_file(fd);
	return 0;
}
