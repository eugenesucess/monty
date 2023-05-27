#include "monty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

gl_v vars;
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t opcode[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (strcmp(instruct[i].opcode, opc) == 0)
			break;
	}

	return (instruct[i].f);
}
	
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
		f = get_opcodes(opcode);
		if (!f)
		{
			fprintf(stderr, "L%u: ", line_count);
			fprintf(stderr, "unknown instruction %s\n", opcode);
			free(vars.buffer);
			free(vars.file);
			free(*head);
			exit(EXIT_FAILURE);
		}
		
		vars.arg = strtok(NULL, " \t\n");
		f(&head line_count);
	}
	vars.line_count = line_count;
	printf("%d\n", line_count);
	printf("%s\n", buffer);
	free(buffer);
	fclose(fd);

	return (0);
}

