#include "monty.h"

static stack_t **stack_head; /* Global stack head */

/**
* global_free - Frees a stack.
*/

void global_free(void)
{
	stack_t *node_to_free;
	stack_t *next_node = NULL;

	node_to_free = *stack_head; /* Get global stack head */

	/* Free each node in the stack */
	while (node_to_free)
	{
		next_node = node_to_free->next; /* Save next node */
		free(node_to_free); /* Free current node */
		node_to_free = next_node; /* Move to next node */
	}
}

/**
* main - Program entry point
* @argc: Argument count
* @argv: Argument vector
*
* Return: 0 on success, 1 on failure
*/

int main(int argc, char *argv[])
{
	stack_t *local_stack_head; /* Local stack head */

	if (argc != 2) /* Validate argument count */
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	local_stack_head = NULL; /* Initialize local stack head */
	/* Assign local stack head to global pointer */
}