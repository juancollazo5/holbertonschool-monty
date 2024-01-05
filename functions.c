#include "monty.h"

/* Function to read and process line
void readprocess_line(char *line, stack_t **stack)
	{
	char *opcode;
	int n;

	/* If line is blank exit */
	if line[0] == '\n')

	return;
	}

	opcode = strtok(line, "\t\n"); /* Extract the opcode from the line */
	if (opcode == NULL) /* Checks if theres an opcode. Otherwise skip line */
	{
	return;
	}

	/* Compare and process the opcodes */

	if (strcmp(opcode, "push") == 0)
	{

	/* Gets the argument for "push")
	char *arg = strtok(NULL, " \t\n");

	/* Verify if argument is valid */
	if (arg == NULL || !isdigit(*arg))
	{
	fprintf(stderr, "Error: push without an interger\n");
	exit(EXIT_FAILURE);
	}

