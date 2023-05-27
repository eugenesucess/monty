#include "monty.h"

void _push(stack_t **stack,unsigned int daa) 
{
	stack_t *ptr;
	int data = atoi(vars.arg);
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		exit(1);
new_node->n = data;
new_node->prev = NULL;
ptr = *stack;
*stack = new_node;
new_node->next = ptr;

if (ptr != NULL)
	ptr->prev = *stack;
}
