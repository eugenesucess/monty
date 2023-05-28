#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
int number;

/*add node at the beg of the stack*/
void push_stack(stack_t **top, unsigned int line_number)
{
	(void)line_number;
	stack_t *newNode;
	
	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		fprintf(stderr, "Can't malloc'");
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
	ptr = *top;

	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

void free_stack(stack_t *top)
{
	stack_t *temp;

	if (top == NULL)
		return;
	while (top != NULL)
	{
		temp = top;
		top = top->next;
		free(temp);
	}
	free(top);
}
