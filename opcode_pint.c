#include "monty.h"

/**
* pint - Prints the value at the top of the stack
* @stack: Double pointer to the top of the stack
* @line_number: The line number of the command in the file
*
* If the stack is empty, it prints an error message and exits the program
* with the status EXIT_FAILURE.
*/

void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
