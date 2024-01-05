#include "monty.h"

/* Function to push a value to the stack data structure */
        void push(stack_t **stack, int n)
        {
        stack_t *new_node = malloc(sizeof(stack_t)); /* Allocate memory for the new node */

        if (new_node == NULL)
        {
        fprintf(stderr, "Error: malloc failed\n"); 
        exit(EXIT_FAILURE);
        }

	new_node->n = n;
	new_node->next = *stack;
	*stack = new_node;
	}
