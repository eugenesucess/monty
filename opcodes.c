#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int number;

void (*get_opcode(char *parsed))(stack_t **top, unsigned int)
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
		i++;
	}
}

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
			*/
	/*	else
		{
			f = get_opcode(command);
			f(&top, line_count);
		}
		line_count++;
	}*/
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
