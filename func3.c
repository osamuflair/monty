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

/**
 * _pchar - prints the char at the top of the stack, followed by a new line.
 * @stack12: the pointer to the topmost element
 * @m: the line number
 * Return: void
 */
void _pchar(stack_t **stack12, unsigned int m)
{
	if ((*stack12) == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", m);
		exit(EXIT_FAILURE);
	}
	if ((*stack12) < 0 || (*stack12) > 250)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range", m);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%c", (*stack12)->n);
}

/**
 * _pstr - prints the string starting at the top
 * of the stack, followed by a new line.
 * @stack13: the pointer to the topmost element
 * @n: the line number
 * Return: void
 */

void _pstr(stack_t **stack13, __attribute__((unused))unsigned int n)
{
	stack_t *temp;

	if ((*stack13) == NULL)
        {
                fprintf(stdout, "\n");
        }
	temp = (*stack13);
	while (temp->n != 0 && (temp->n > 0 && temp->n < 250) && temp != NULL)
	{
		fprintf(stdout, "%c", temp->n);
		temp = temp->next;
	}
	fprintf(stdout, "\n");
}

/**
 * _rotl - rotates the stack to the top
 * @stack14: the pointer to the topmost element
 * @o: the line number
 * Return: void
 */

void _rotl(stack_t **stack14, __attribute__((unused))unsigned int o)
{
	stack_t *temp;

	if ((*stack14) == NULL || (*stack14)->next == NULL)
		return ();
	else
	{
		temp = (*stack14);

		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = (*stack14);
		(*stack14)->prev = temp;
		(*stack14) = (*stack14)->next;
		temp = temp->next;
		temp->next = NULL;
		(*stack14)->prev = NULL;
	}
}

/**
 * _rotr - rotates stack to bottom
 * @stack15: the pointer to the topmost element
 * @p: the line number
 * Return: void
 */

void _rotr(stack_t **stack15, __attribute__((unused)) unsigned int p)
{
        stack_t *temp;
	stack_t *pre;

        if ((*stack15) == NULL || (*stack15)->next == NULL)
                return ();
	else
	{
		temp = (*stack15);

                while ((*stack15)->next != NULL)
                {
                        pre = (*stack15);
                        (*stack15) = (*stack15)->next;
                }
		(*stack15)->next = temp->next;
		temp->next = NULL;
                temp->prev = pre;
                pre->next = temp;
                (*stack15)->prev = NULL;
        }
}
