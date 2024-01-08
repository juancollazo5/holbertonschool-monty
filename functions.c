#include "monty.h"

/**
 * pint - print top node on stack
 * @head: pointer to pointer of first node
 * @counter: line counter
 */

void pint(stack_t **head, unsigned int counter)
{
/* Print an error and exit if trying to pint from an empty stack */
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
/* Print the value of the top node in the stack */
	printf("%d\n", (*head)->n);
}

/* others new functions on the next lines */
