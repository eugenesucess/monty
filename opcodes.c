#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int number;

void (*get_opcode(char *parsed,  unsigned int line))(stack_t **top, unsigned int)
{
	int i = 0;
	instruction_t opt[] = {
		{"push", push_stack},
		{"pall", pall_stack},
//		{"pint", pint_stack},
//		{"pop", pop_stack},
//		{"swap", _swap},
//		{"nop", _nop},
		{NULL, NULL}	
	};
	
	while (opt[i].opcode != NULL)
	{
		if (strcmp(opt[i].opcode, parsed) == 0)
		{
			return (opt[i].f);
		}
		else
		{
			fprintf(stderr, "unknown instruction");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return NULL;
}

int is_number(char *parsed)
{
	int i;

	if (parsed == NULL)
		return (-1);

	for (i = 0; parsed[i] != '\0'; i++)
	{
		if (parsed[i] != '-' && isdigit(parsed[i]) == 0)
			return (-1);
	}
	return (1);
}
