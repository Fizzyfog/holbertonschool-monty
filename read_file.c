#include "monty.h"

/**
 * read_file - This function opens a file and reads its content line by line.
 * Each line is parsed for commands and executed accordingly.
 * @file: The name of the file to be opened and read.
 * @stack: Pointer to the stack's top.
 */

void read_file(char *file, stack_t **stack)
{
	size_t len;
	ssize_t read_line;
	unsigned int num = 0;

	char *line = NULL;

	FILE *fd;
	char *command;

	/* Open the file */
	fd = fopen(file, "r");
	if (!fd)
	{
		/* Print error and exit if file can't be opened */
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	/* Read the file line by line */
	while ((read_line = getline(&line, &len, fd)) != -1)
	{
		/* Tokenize the line to get the command */
		command = strtok(line, " \n\t");
		num++;

		/* If a command is found(trouvé), parse(traite) it */
		if (command)
			parse_command(stack, command, num);
	}

	/* Free the line buffer */
	if (line)
		free(line);

	/* Close the file */
	fclose(fd);
}
