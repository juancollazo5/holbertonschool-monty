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

return 0;
}
