#include "monty.h"
/**
 * addqueue - add node to tail of queue
 * @n: new value
 * @head: head of the queue
 *
 * Return: none
 */

void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	temp = *head;  /* Store the head of the queue in a temporary variable */
	new_node = malloc(sizeof(stack_t));  /* Allocate memory for a new node */

	if (new_node == NULL)
		printf("Error\n");  /* Print an error message if memory allocation fails */

	new_node->n = n; /* Set the data value of the new node */
	new_node->next = NULL; /* The new node will be the last node, so its next is NULL */

	if (temp)
	{
		while (temp->next) /* Move to the last node in the current queue */
			temp = temp->next;
	}
	if (!temp)
	{
		/* If the queue is empty, set the head to the new node */
		*head = new_node;

		/* The new node is now the only node, so its previous is NULL */
		new_node->prev = NULL;
	}
	else
	{
		/* Link the last node in the current queue to the new node */
		temp->next = new_node;

		/* Set the previous pointer of the new node to the last node */
		new_node->prev = temp;
	}
}
