#include "monty.h"
/**
 * _push - it adds an element on top of a stack
 * @a: the element
 * Return: void
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	size_t arg1, i = 0;

	node = malloc(sizeof(stack_t));
	while (1)
	{
		if (bus.arg[i] == ' ')
			i++;
		else
			break;
	}
	if (is_int(bus.arg) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		arg1 = atoi(bus.arg);
	if ((*stack) == NULL)
	{
		(*stack) = node;
		(*stack)->prev = (*stack)->next = NULL;
		(*stack)->n = arg1;
	}
	else
	{
		node->next = (*stack);
		(*stack)->prev = node;
		node->prev = NULL;
		(*stack) = node;
		node->n = arg1;
	}
}

/**
 * _pall - it prints all elements from top of stack
 * @stack: the pointer to the first element
 * @line_number: the number of line where the function is called
 * Return: void
 */

void _pall(stack_t **stack1, unsigned int n)
{
	stack_t *temp;

	temp = (*stack1);
        if ((*stack1) == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction pall\n", n);
		exit(EXIT_FAILURE);
	}
	else
        {
		while(temp)
		{
			fprintf(stdout, "%d", temp->n);
			temp = temp->next;
		}
	}
}

/**
 * _pop - deletes the element at the top of the stack
 * @stack4: the pointer to the topmost element
 * @d: the line number
 * Return: void
 */

void _pop(stack_t **stack4, unsigned int e)
{
        stack_t *temp;

        if ((*stack4) == NULL)
        {
                fprintf(stderr, "L%d: can't pop an empty stack\n", e);
                exit(EXIT_SUCCESS);
        }
        else
        {
                temp = (*stack4);
                (*stack4) = (*stack4)->next;
                (*stack4)->prev = NULL;
                free(temp);
        }
}

/**
 * _pint - prints the element ontop of the stack
 * @stack3: the pointer to the topmost element
 * @c: the line number
 * Return: void
 */

void _pint(stack_t **stack3, unsigned int c)
{
        if ((*stack3) == NULL)
        {
                fprintf(stderr, "L%d: can't pint, stack empty\n", c);
                exit(EXIT_FAILURE);
        }
        else
        {
                fprintf(stdout, "%d", (*stack3)->n);
        }
}

/**
 * _swap - swaps the top two elements in stack
 * @stack5: the pointer to the topmost element
 * @f: the line number
 * Return: void
 */

void _swap(stack_t **stack5, unsigned int f)
{
	if ((*stack5) == NULL || (*stack5)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", f);
		exit(EXIT_FAILURE);
	}
	stack_t *temp;

	temp = (*stack5);
	(*stack5) = (*stack5)->next;
	temp->next = (*stack5)->next;
	temp->prev = (*stack5);
	(*stack5)->next = temp;
	(*stack5)->prev = NULL;
}
