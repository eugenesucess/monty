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
		{"nop", _nop},
		{NULL, NULL}
	};
	int i;

	for (i = 0; opcode[i].opcode; i++)
	{
		if (strcmp(opcode[i].opcode, opc) == 0)
			break;
	}

	return (opcode[i].f);
}
	
int main(int argc, char **argv)
{
	void (*f)(stack_t **stack, unsigned int line_number);
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
		if (!opcode)
		{
			fprintf(stderr, "no");
			exit(EXIT_FAILURE);
		}
		vars.opc = opcode; /*in order to use struct*/
		if (strcmp(opcode, "push") == 0)
		{
			arg = strtok(NULL, " \t\n");
			if (!arg)
			{
				printf("pops\n");
			}
			vars.arg = arg;
			_push(head, line_count);
			printf("Holla %s\n", arg);
		}
		else if(strcmp(opcode, "pall") == 0)
		{
			printf("MAN");
		}
	}
	vars.line_count = line_count;
	printf("%d\n", line_count);
	printf("%s\n", buffer);
	free(buffer);
	fclose(fd);

	return (0);
}

