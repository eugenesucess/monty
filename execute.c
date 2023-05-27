#include "monty.h"

int execute (stack_t **head, char *content, unsigned int count, FILE *file)
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
	}
	if (vars.opc && opcode[i].opcode == NULL)
	{
		 fprintf(stderr, "L%d: unknown instruction %s\n", count, vars.opc);
		 fclose(file);
		 free(content);
		 free_list(*head);
		 exit(EXIT_FAILURE);
	}
	return (1);
}
