#include "monty.h"

/**
 * pall - Prints all elements in the stack.
 * @stack: A pointer to a pointer to the stack structure.
 * @line_number: The line number of the command in the file
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node = *stack;

	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
	 /* Unused variable */
	(void) line_number;
}
