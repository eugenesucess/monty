#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int number;

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
