#include "monty.h"

/**
 * parse_command - Parse commands and execute corresponding function
 * @stack: Pointer to the stack's top
 * @user_cmd: The command to be executed
 * @line_number: The line number of the command in the file
 */
void parse_command(stack_t **stack, char *user_cmd, unsigned int line_number)
{
	int index;

	/* Array of commands and their functions */
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL} /* End of array */
	};

		/* Loop through instructions */
	for (index = 0; instructions[index].command != NULL; index++)
	{
		/* If command matches, execute function */
		/*Si l'command correspond, la fonction est exécutée*/
		if (strcmp(user_cmd, instructions[index].command) == 0)
		{
			instructions[index].fct(stack, line_number);
			return;
		}
	}

	/* If command not found and not a comment */
	/*Si l'command n'est pas trouvé et qu'il ne s'agit pas d'un commentaire*/
	if (strlen(user_cmd) != 0 && user_cmd[0] != '#')
	{
		/* Error message */
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, user_cmd);
		exit(EXIT_FAILURE);
	}
}
