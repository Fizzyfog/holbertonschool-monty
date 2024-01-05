#include "monty.h"

/**
 * pall - Prints all elements in the stack.
 * @stack: A pointer to a pointer to the stack structure.
 * @line_number: The line number of the command in the file
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	 /* Unused variable */
	(void) line_number;
}
