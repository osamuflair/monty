#include "monty.h"

/**
 * _mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @stack11: the pointer to the topmost element
 * @l: the line number
 * Return: void
 */

void _mod(stack_t **stack11, unsigned int l)
{
	stack_t *temp;

	if ((*stack11) == NULL || (*stack11)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", l);
		exit(EXIT_FAILURE);
	}
	temp = (*stack10)->next;
        (*stack10)->n = temp->n % (*stack10)->n;
        (*stack10)->next = temp->next;
        free(temp);
}
