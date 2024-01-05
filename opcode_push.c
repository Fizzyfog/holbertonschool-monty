#include "monty.h"

/**
* push - Pushes an integer onto the stack.
* @stack: A pointer to a pointer to the stack structure.
* @line_number: The integer to be pushed onto the stack.
* Return: 0 if successful, 1 otherwise.
*/

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stack_node;
	char *next_token;

	int number_to_push;

	next_token = strtok(NULL, " \n\t");
	if (next_token == NULL || strchr(next_token, '.') != NULL ||
		strchr(next_token, ',') != NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	number_to_push = atoi(next_token);
	/*printf("token [%s] n [%d]\n", next_token, number_to_push);*/
	if (number_to_push == 0 && strcmp(next_token, "0") != 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_stack_node = malloc(sizeof(stack_t));
	if (new_stack_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_stack_node->n = number_to_push;
	new_stack_node->prev = NULL;
	new_stack_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_stack_node;

	*stack = new_stack_node;
}
