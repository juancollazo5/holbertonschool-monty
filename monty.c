#include "monty.h"
stack_t;

int main(int argc, char *argv[])
{
	/* checks the command line arguments to ensure only one file is provided. If not print error message */

	if (argc !=2) /* checks if number of arguments is 2 (program name and file name) */
		{
		fprintf(stderr, "USAGE: monty file\n"); /* prints error message then exits */
		exit(EXIT_FAILURE);
		}
	/* Attempt to open the file */
	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
	fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
	exit(EXIT_FAILURE);
	}

return 0;
}
