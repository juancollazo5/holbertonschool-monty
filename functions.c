#include "monty.h"

/**
 * readprocess_line - Reads and processes each line of a file
 * @line: Line read from a file
 * @stack: Modify stack within function
 */
void readprocess_line(char *line, stack_t **stack)
{
	char *opcode;
	int n;
	static unsigned int line_number = 0;

	/* If line is blank exit */
	if (line[0] == '\n')
		return;

	opcode = strtok(line, "\t\n"); /* Extract the opcode from the line */

	if (opcode == NULL) /* Checks if theres an opcode. Otherwise skip line */
	{
		return;
	}

	/* Compare and process the opcodes */

	if (strcmp(opcode, "push") == 0)
	{

		/* Gets the argument for "push" */
		char *arg = strtok(NULL, " \t\n");

		/* Verify if argument is valid */
		if (arg == NULL || !isdigit(*arg))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}

		n = atoi(arg);
		push(stack, n);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(*stack);
	}
	/* other opcodes */
}
