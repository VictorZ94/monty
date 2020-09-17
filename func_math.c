#include "monty.h"

/**
 * _sub - function sub two numbers
 *  @stack: top of the stack
 * @line_number: line number
 *
 * Return: Nothing.
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	size_t check;
	int tmp;

	check = dlistint_len(*stack);
	if (check < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next->n - (*stack)->n;
	add_dnodeint(stack, tmp);
	delete_dnodeint_at_index(stack, 1);
	delete_dnodeint_at_index(stack, 1);
}

void _div(stack_t **stack, unsigned int line_number)
{
	size_t check;
	int tmp;

	check = dlistint_len(*stack);
	if (check < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next->n / (*stack)->n;
	add_dnodeint(stack, tmp);
	delete_dnodeint_at_index(stack, 1);
	delete_dnodeint_at_index(stack, 1);
}

void _mul(stack_t **stack, unsigned int line_number)
{
	size_t check;
	int tmp;

	check = dlistint_len(*stack);
	if (check < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next->n * (*stack)->n;
	add_dnodeint(stack, tmp);
	delete_dnodeint_at_index(stack, 1);
	delete_dnodeint_at_index(stack, 1);
}

void _mod(stack_t **stack, unsigned int line_number)
{
	size_t check;
	int tmp;

	check = dlistint_len(*stack);
	if (check < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next->n % (*stack)->n;
	add_dnodeint(stack, tmp);
	delete_dnodeint_at_index(stack, 1);
	delete_dnodeint_at_index(stack, 1);
}
