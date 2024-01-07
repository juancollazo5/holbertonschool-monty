#include "monty.h"

/**
 * main - Main function for monty interpreter
 * @argc: Number of command line arguments
 * @argv: Name of the file to open
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	stack_t *stack = NULL;

	/* checks the command line arguments to ensure only one file is provided. */
	/* checks if number of arguments is 2 (program name and file name)*/
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n"); /* prints error message then exits */
		exit(EXIT_FAILURE);
	}

	/* Attempt to open the file */
	FILE *file = fopen(argv[1], "r");

	if (file == NULL) /* if the file trying to open is NULL */
	{
		/* print error message and exit */
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, file) != -1) /* Reads the file line by line */
	{
		readprocess_line(line, &stack); /* Process each line provided */
	}

	free(line);
	free_stack(stack);
	fclose(file);
	return (0);
}
