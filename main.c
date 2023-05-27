#include "monty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

gl_v vars;
int main(int argc, char **argv)
{
	FILE *fd;
	char *buffer, *opcode, *arg;
	size_t size =0;
	unsigned int line_count = 0;
	size_t nreads = 1;
	stack_t **head = NULL;

	buffer = malloc(sizeof(char *) * 1024);
	if (!buffer)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	vars.file = fd;
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file <%s>\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((nreads = getline(&buffer, &size, fd) != -1))
	{
		line_count++;
		opcode = strtok(buffer, " \t\n");
		vars.opc = opcode; /*in order to use struct*/
		if (opcode == NULL)
		{
			fprintf(stderr, "L<%u>: unknown instruction <%s>", line_count, opcode);
			exit(EXIT_FAILURE);
			free(buffer);
			free(opcode);
		}
		execute(head, buffer, line_count);
		printf("%s\n", opcode);
	}
	vars.line_count = line_count;
	printf("%d\n", line_count);
	printf("%s\n", buffer);
	free(buffer);
	fclose(fd);

	return (0);
}

