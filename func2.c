#include "monty.h"

/**
 * _add - it adds the top two element, and makes them one...
 * @stack6: the pointer to the topmost element
 * @g: the line number
 * Return: void
 */

void _add(stack_t **stack6, unsigned int g)
{
	stack_t *temp;

	if ((*stack6) == NULL || (*stack6)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", g);
		exit(EXIT_FAILURE);
	}
	temp = (*stack6)->next;
	(*stack6)->n = (*stack6)->n + temp->n;
	(*stack6)->next = temp->next;
	free(temp);
}

/**
 * _nop - it dosen't do a thing...
 * @stack7: the pointer to the topmost elemwnt
 * @h: line number
 * Return: void
 */

void _nop(stack_t **stack7, unsigned int h)
{
	return ();
}

/**
 * _sub - subtracts the top element of the stack
 * from the second top element of the stack
 * @stack8: the pointer to the topmost element
 * @i: the line number
 * Return: void
 */

void _sub(stack_t **stack8, unsigned int i)
{
	stack_t *temp;

        if ((*stack8) == NULL || (*stack8)->next == NULL)
        {
                fprintf(stderr, "L%d: can't sub, stack too short\n", i);
                exit(EXIT_FAILURE);
        }
        temp = (*stack8)->next;
        (*stack8)->n = temp->n - (*stack8)->n;
        (*stack8)->next = temp->next;
        free(temp);
}

/**
 * _div - divides the second top element of the stack
 * by the top element of the stack
 * @stack9: the pointer to the topmost element
 * @j: the line number
 * Return: void
 */

void _div(stack_t **stack9, unsigned int j)
{
	stack_t *temp;

	if ((*stack9) == NULL || (*stack9)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", j);
		exit(EXIT_FAILURE);
        }
	if ((*stack9)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", j);
		exit(EXIT_FAILURE);
	}
        temp = (*stack9)->next;
	(*stack9)->n = temp->n / (*stack9)->n;
        (*stack9)->next = temp->next;
	free(temp);
}

/**
 * _mul - multiplies the second top element of the stack
 * with the top element of the stack.
 * @stack10: the pointer to the topmost elemwnt
 * @k:;the line number
 * Return: void
 */

void _mul(stack_t **stack10, unsigned int k)
{
	stack_t *temp;

	if ((*stack10) == NULL || (*stack10)->next == NULL)
        {
                fprintf(stderr, "L%d: can't mul, stack too short\n", k);
		exit(EXIT_FAILURE);
        }
        temp = (*stack10)->next;
        (*stack10)->n = temp->n * (*stack10)->n;
	(*stack10)->next = temp->next;
        free(temp);
}
