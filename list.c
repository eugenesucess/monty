#include "monty.h"
#include <stdlib.h>

void free_list(stack_t *head)
{
	stack_t *ptr;
	ptr = head;

	while (head != NULL)
	{
		ptr = head->next;
		free(head);
		head = ptr;
	}
}
