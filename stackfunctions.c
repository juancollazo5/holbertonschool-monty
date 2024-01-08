#include "monty.h"

/**
 * push - Function to push a value to the stack data structure
 * @head: Pointer to the top of the stack
 * @counter: line number
 */
void push(stack_t **head, unsigned int counter)
{
	int i, m = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			m++;
		for (; bus.arg[m] != '\0'; m++)
		{
			if (bus.arg[m] > 57 || bus.arg[m] < 48)

		/* Set flag if the argument contains non-digit characters */
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			/* Print error and exit if argument is not a valid integer */
			exit(EXIT_FAILURE); }
		}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		/* Print error and exit if there is no argument provided */
		exit(EXIT_FAILURE);
	}
	/* Convert the argument to an integer */
	i = atoi(bus.arg);

	if (bus.lifi == 0)

		/* Add the integer to the stack if lifo mode is set */
		addnode(head, i);
	else
		/* Add the integer to the queue if lifo mode is not set */
		addqueue(head, i);
}

/**
* pall - Function to print all values on the stack
* @head: pointer to pointer of first node
* @counter: line counter (not used)
*
* Return: none
*/

void pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter; /* Suppress unused parameter warning */

	h = *head; /* Set a temporary pointer to the head of the stack */
	if (h == NULL)
		return; /* If the stack is empty, return without printing anything */

	while (h)
	{
		printf("%d\n", h->n); /* Print the value of the current node */
		h = h->next; /* Move to the next node in the stack */
	}
}
