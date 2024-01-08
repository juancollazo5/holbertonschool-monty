#include "monty.h"

/**
* free_stack - free the stack
* @stack: pointer to the stack
*
* Return: none
*/
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack; /* Store the current node in a temporary variable */
		stack = stack->next; /* Move to the next node in the stack */
		free(temp); /* Free the memory occupied by the current node */
	}
}
