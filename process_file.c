#include "monty.h"

/**
* file_process - Function that loops through and tokenizes file lines
* @file: File to loop through
*
* Return: Always Void
*/
void file_process(FILE *file)
{
	int line_num;
	char *line = NULL;
	size_t line_size = 0;

	for (line_num = 1; getline(&line, &line_size, file) != -1; line_num++)
		line_process(line, line_num);

	free(line);
}

/**
* line_process - Function that tokenizes file line
* @file_line: File line to tokenize
* @line_num: File line number to keep track of failures
*
* Return: Always void
*/
void line_process(char *file_line, int line_num)
{
	char *line = NULL, *line_copy = NULL, *token;
	char **tokenized_line = NULL;
	int num_tokens, i;

	line_copy = malloc(sizeof(char) * (strlen(file_line) + 1));
	if (line_copy == NULL)
	{
		free(file_line);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	strcpy(line_copy, line);

	token = strtok(line, " \n");
	if (token == NULL)
	{
		free(file_line);
		free(line_copy);
		return;
	}

	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, " \n");
	}
	num_tokens++;

	tokenized_line = malloc(sizeof(char *) * num_tokens)
	if (tokenized_line == NULL)
	{
		free(file_line);
		free(line_copy);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line_copy, " \n");
	for (i = 0; token != NULL; i++)
	{
		tokenized_line[i] = malloc(sizeof(char) * (strlen(token) + 1));
		strcpy(tokenized_line[i], token);
		token = strtok(NULL, " \n");
	}
	tokenized_line[i] = NULL;

	free(line_copy);
	if (tokenized_line[1])
		get_op_func(tokenized_line[0], tokenized_line[1], line_num);
	else
		get_op_func(tokenized_line[0], NULL, line_num);
}

/**
* *get_op_func - Function that finds correct op function
* @opcode: opcode to check
* @arg: argument for push
*
* Return: Always Void
*/
void (*get_op_func(const char *opcode, char *arg, unsigned int line_num))(stack_t **stack, unsigned int line_number)
{
	instruction_t op[] = {
		{"push", push},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"pall", pall},
		{"pint", pint},
		{"nop", nop},
		{NULL, NULL}
	};
	int i;

	i = 0;

	while (op[i].opcode != NULL)
	{
		if (*(op[i].opcode) == *opcode)
		{
			if (*arg == NULL)
				exec_op(op[i].f, NULL);
			else
				exec_op(op[i].f, arg)
		}
		i++;
	}
	free(opcode);
	free(arg);
	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
	exit(EXIT_FAILURE);
}

/**
* exec_op - Function that executes an instruction
* @f: Instruction function to execute
* @arg: argument to push function
*
* Return: Always Void
*/
void exec_op(void (*f)(stack_t **stack, unsigned int line_number), char *arg);
{
}