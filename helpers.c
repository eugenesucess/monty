#include "monty.h"
#include <stdio.h>
#Inclued <stdlib.h>
int number;

/*add node at the beg of the stack*/
void push_stack(stack_t **top, unsigned int line_number)
{
	(void)line_number;
	stack_t *newNode;
	
	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		fprint(stderr, "Can't malloc'");
		exit(EXIT_FAILURE);
	}
	
	newNode->n = number;
	newNode->prev = NULL;

	if (*top == NULL)/*validate if stack is empty*/
	{
		newNode->next = NULL;
		*top = newNode;
	}
	else
	{
		newNode->next = *top;
		(*top)->prev = newNode;
		*top = newNode;
	}
}
void pall_stack(stack_t **top, unsigned int line_number)
{
	stack_t *ptr;
	(void)line_number;
	
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
