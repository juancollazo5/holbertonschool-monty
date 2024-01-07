#include "monty.h"

/**
 * push - Function to push a value to the stack data structure
 * @stack: Pointer to the top of the stack
 * @n: Value to be pushed onto the stack
 */
void push(stack_t **stack, int n)
{
	/* Allocate memory for the new node */
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = *stack;
	*stack = new_node;
}

/**
 * pall - Function to print all values on the stack
 * @stack: Pointer to the top of the stack
 */
void pall(stack_t *stack)
{
	while (stack != NULL)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}
