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
