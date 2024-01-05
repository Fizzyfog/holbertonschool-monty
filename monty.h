#ifndef MAIN__H
#define MAIN__H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
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
* struct instruction_s - command and its function
* @command: the command
* @fct: function to handle the command
*
* Description: command and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
		char *command;

		void (*fct)(stack_t **stack, unsigned int line_number);

} instruction_t;

/* Prototypes */

void read_file(char *file, stack_t **stack);
void parse_command(stack_t **stack, char *user_cmd, unsigned int line_number);

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

#endif
