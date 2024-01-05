#include "monty.h"

void readprocess_line(char *line stack_t **stack);

int main(int argc, char *argv[])
{

char *line = NULL;
size_t len = 0;
stack_t *stack = NULL;

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

	char *line = NULL;
	size_t len = 0;
	stack_t *stack = NULL;


	while (getline(&line, &len, file) != -1) /* Reads the file line by line */
	{
	readprocess_line(line, &stack); /* Process each line provided */
	}

	/* Look up the opcode in the instruction table */
	instruction_t *instruction = lookup_opcode(line);

	/* Execute the instruction */
	instruction->f(&stack, atoi(line + 1));
	}

	free(line);
	free_stack(stack);
	fclose(file);
	return 0;
}

