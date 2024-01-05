#include "monty.h"

/**
* push - Pushes an integer onto the stack.
* @stack: A pointer to a pointer to the stack structure.
* @line_number: The integer to be pushed onto the stack.
* Return: 0 if successful, 1 otherwise.
*/

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *token;

	int n;

	token = strtok(NULL, " \n\t");
	if (token == NULL || strchr(token, '.') != NULL || strchr(token, ',') != NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = atoi(token);
	/*printf("token [%s] n [%d]\n", token, n);*/
	if (n == 0 && strcmp(token, "0") != 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
