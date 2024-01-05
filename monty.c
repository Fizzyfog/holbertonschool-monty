#include "monty.h"

static stack_t **stack_head;

/**
* global_free - This function frees a stack.
*/

void global_free(void)
{
	stack_t *to_free;
	stack_t *temp = NULL;
	/* Get the global head of the stack */
	to_free = *stack_head;

	/* Loop through the stack */
	while (to_free)
	{
		/* Save the next element */
		temp = to_free->next;
		/* Free the current element */
		free(to_free);
		/* Move to the next element */
		to_free = temp;
	}
}

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, 1 on failure
 */

int main(int argc, char *argv[])
{
	stack_t *head; /*Declare a pointer to the head of the stack*/

	if (argc != 2) /*Check if the number of arguments is not equal to 2*/
	{
		/*If so, print an error message and exit the program*/
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	head = NULL;
	/* Assign the address of the head of the stack to the global pointer */
	stack_head = &head;
	/* Read the file passed as argument and fill the stack */
	read_file(argv[1], &head);
	/* Register the function global_free to be called when the program exits */
	atexit(global_free);
	exit(EXIT_SUCCESS);
}
