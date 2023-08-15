#include "monty.h"

/**
* main - File interpreter for monty bytecode files
* @argc - Number of args to program
* @argv - Array of strings containing arguments
*
* Return: 0 if Success, -1 if Failure
*/
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	FILE *fp;

	if (argc < 2 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	file_process(fp);

	fclose(fp);
	return (0);
}
