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
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
