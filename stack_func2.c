#include "monty.h"

/**
 * _pint - print top of the stack
 * @stack: top of the stack
 * @line_number: line number
 *
 * Return Void
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * _pop - remove top of the stack
 * @stack: top of the stack
 * @line_number: line number
 *
 * Return Void
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (!*stack || !stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	*stack = (*stack)->next;
	free(current);
}

/**
 * _swap - chance two number of node
 * @stack: top of the stack
 * @line_number: line number
 *
 * Return Void
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	size_t check;
	int tmp;

	check = dlistint_len(*stack);
	if (check < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}
