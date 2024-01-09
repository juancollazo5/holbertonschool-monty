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

/**
 * pop - print top node on stack
 * @head: pointer to pointer of first node
 * @counter: line counter
 */

void pop(stack_t **head, unsigned int counter)
{
	stack_t *h;
/* Print an error and exit if trying to pop from an empty stack */

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	h = *head; /* Store the current top node in a temporary variable */
	*head = h->next; /* Update the head pointer to the next node in the stack */
	free(h); /* Free the memory occupied by the removed top node */
}

/* others new functions on the next lines */
