#include "monty.h"
gl_v vars;

/**
 *  * f_pint - prints the top
 *   * @head: stack head
 *    * @counter: line_number
 *     * Return: no return
 *     */
void _pint(stack_t **head, unsigned int counter)
{
	int passed;

	if (*head == NULL)
		{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
	fclose(vars.file);
	free(vars.buffer);
	free_list(*head);
	exit(EXIT_FAILURE);
	}
	passed = atoi(vars.arg);
	(*head)->n = passed;
		printf("%d\n", (*head)->n);
}

void _nop(stack_t **head, unsigned int counter)
{
		(void) counter;
			(void) head;
}

void _pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

void _pop(stack_t **head, unsigned int counter)
{
	stack_t *h;
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(vars.file);
		free(vars.buffer);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
