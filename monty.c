#include "monty.h"
#define _GNU_SOURCE

/* Global variable to hold shared data across functions */
bus_t bus = {NULL, NULL, NULL, 0};

/**
* main - monty code interpreter
* @argc: argument counter
* @argv: argument vector
*
* Return: 0
*/
int main(int argc, char *argv[])
{
	char *content; /* Variable to store each line of content from the file */
	FILE *file; /* File pointer to open and read the file */
	size_t size = 0; /* Size of the content buffer */
	ssize_t read_line = 1; /* Number of characters read in each line */
	stack_t *stack = NULL; /* Stack data structure, initially set to NULL */
	unsigned int counter = 0; /* Counter to keep track of the line number in the file */

	/* Check for correct argument count */
	if (argc != 2)
	{
	/* Print error message and exit */
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}


	file = fopen(argv[1], "r"); /* Open the file in read mode */

	/* Store the file pointer in the global bus structure */
	bus.file = file;

	if (!file)
	{
		/* Print error message and exit */
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (read_line > 0)
	{
		content = NULL;

		/* Read a line from the file into content */
		read_line = getline(&content, &size, file);

		/* Store the content in the global bus structure */
		bus.content = content;

		counter++;

		if (read_line > 0)

			/* Process the content using the rpl function */
			rpl(content, &stack, counter, file);

		free(content);
	}

	free_stack(stack);
	fclose(file);
	return (0);
}
