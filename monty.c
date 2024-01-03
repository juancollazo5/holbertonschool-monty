#include "monty.h"

int main(int argc, char *argv[])
{

stack_t *stack = NULL;
char *line = NULL;
size_t line_length = 0;


/* checks the command line arguments to ensure only one file is provided. If not print error message */

if (argc !=2) /* checks if number of arguments is 2 (program name and file name) */
{
fprintf(stderr, "USAGE: monty file\n"); /* prints error message then exits */
exit(EXIT_FAILURE);
}

/* Attempt to open the file */
FILE *file = fopen(argv[1], "r");

if (file == NULL) /* if the file trying to open is NULL */
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]); /* print error message and exit */
exit(EXIT_FAILURE);
}

while (getline(&line, &line_length, file) != -1)
{
/* Strip whitespace from the line */
line = strtok(line, " \t\n");

/* Check if the line is empty */
if (line == NULL)
continue;

/* Check if the line is a comment */
if (line[0] == '#')
continue;

/* Look up the opcode in the instruction table */
instruction_t *instruction = lookup_opcode(line);

/* Execute the instruction */
instruction->f(&stack, atoi(line + 1));
}

free_stack(stack);
fclose(file);

return (0);
}
