#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/*Data Structures*/

/**
* struct stack_s - doubly linked list representation of a stack
* @n: integer
* @prev: points to the previous element of the stack
* @next: points to the next element of the stack
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* process_file.c */
void file_process(FILE *file);
void line_process(char *file_line, int line_num);
void (*get_op_func(const char *opcode, char *arg, int line_num))(stack_t **stack, unsigned int line_number);
void exec_op(void (*f)(stack_t **stack, unsigned int line_number), char *arg);

/* op_funcs1.c */
void push(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);

/* op_funcs2.c */
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

/* Global Variable (Point to top of stack) */
extern stack_t *stack;
#endif