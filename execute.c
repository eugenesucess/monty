#include "monty.h"

int execute (stack_t **head, char *content, unsigned int count)
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
	int i = 0;
	vars.arg = strtok(NULL, " \t\n");
	for (i = 0; opcode[i].opcode, vars.opc; i++);
	{
		if (strcmp(opcode[i].opcode, vars.opc) == 0)	
		{
			opcode[i].f(head, count);
			return (0);
		}
		if ((strcmp(opcode[i].opcode, "push") == 0) && (vars.arg == NULL))
		{
			fprintf(stderr, "args not count");
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}
