#include "monty.h"

/**
* addnode - add node to top of stack
* @head: first node
* @n: new value
*
* Return: none
*/

void addnode(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	/* Store the current head of the stack in a temporary variable */
	temp = *head;
	new_node = malloc(sizeof(stack_t)); /* Allocate memory for a new node */

	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (temp)

	/*If the stack is not empty, update the previous pointer of the current head*/
		temp->prev = new_node;

	new_node->n = n; /* Set the data value of the new node to the given integer */

	/* Set the next pointer of the new node to the current head of the stack */
	new_node->next = *head;

	/* Set the previous pointer of the new node to NULL, as it is the new head */
	new_node->prev = NULL;

	/* Update the head of the stack to the new node */
	*head = new_node;
}
