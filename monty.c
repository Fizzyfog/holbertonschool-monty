#include "monty.h"
#include "global.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
*/
int main(int argc, char *argv[])
{
    FILE *file;// a  pointer used to represent the contents of a file
    char *line = NULL, *opcode;//line is used to store the line read from the file
    //opcode is used to store the opcode read from the line
    size_t length= 0;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");

    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (getline(&line, &length, file) != -1)
    {
        line_number++;
        opcode = strtok(line, " \t\n");

        if (opcode != NULL && opcode[0] != '#')
            executeOp(opcode, line_number, line, file);
    }
    freeAndClose(&stack, line, file);
    return (EXIT_SUCCESS);
}