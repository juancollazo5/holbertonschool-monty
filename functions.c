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

/**
* swap - swap first two elements of stack
* @head: first node
* @counter: line counter
*/

void swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int length = 0, temp;

	h = *head; /* Store the current head of the stack in a temporary variable */

	/* Count the number of elements in the stack */
	while (h)
	{
		h = h->next;
		length++;
	}
	/* Print an error and exit if trying to swap with insufficient elements */
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	/* Reset the temporary variable to the current head of the stack */
	h = *head;

	/* Store the value of the first element in a temporary variable */
	temp = h->n;

	/* Swap the values of the first two elements in the stack */
	h->n = h->next->n;
	h->next->n = temp;
}

/* others new functions on the next lines */
