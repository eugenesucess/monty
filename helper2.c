#include "monty.h"

void _push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;
	if (vars.arg)
	{
		if (vars.arg[0] == '-')
			j++;
		for (; vars.arg[j] != '\0'; j++)
		{
			if (vars.arg[j] > 57 || vars.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(vars.file);
			free(vars.buffer);
			free_list(*head);
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(vars.arg);
	if (vars.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}

void _add(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
		if (len < 2)
		{
			fprintf(stderr, "L%d: can't add, stack too short\n", counter);
			fclose(vars.file);
			free(vars.buffer);
			free_list(*head);
			exit(EXIT_FAILURE);
		}
	h = *head;
	aux = h->n + h->next->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
void _swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(vars.file);
		free(vars.buffer);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
