#include "monty.h"

/**
* rpl - read and process lines from the file
* @content: line to process
* @stack: pointer to the stack
* @counter: line number
* @file: pointer to the input file
* Return: 0
*/
int rpl(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", push},
				{"pall", pall},
				{"pint", pint},
				{"pop", pop},
				{"swap", swap},
				{"nop", nop}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t"); /* Tokenize the content to extract the operation */
	if (op && op[0] == '#')
		return (0); /* Ignore comments (lines starting with '#') */
	bus.arg = strtok(NULL, " \n\t"); /* Extract the argument of the operation */
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			/* Call the corresponding function for the operation */
			opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}

	/* Print an error message for unknown instruction, then clean up and exit */
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
