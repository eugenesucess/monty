#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	if (argc != 2)
	{
		fprintf(stderr, "few arguments");
		exit(EXIT_FAILURE);
	}
	check_open_file(argv);
	return 0;
}
