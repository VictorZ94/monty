#include "monty.h"

/**
 * get_op_func -  function to get structure and pointer function
 * @str: recieve character push, pall, pint function
 *
 * Return: NULL or Operator
 */
instruct_func get_op_func(char *str)
{
	int i;

	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{NULL, NULL}
	};

	i = 0;
	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0)
	{
		i++;
	}
	return (instruct[i].f);
}

/**
 * _push - function add new node at the stack
 * @stack: top of the stack
 * @line_number: line number
 *
 * Return: void.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int push_arg;

	push_arg = 0;
	arg = strtok(NULL, "\n ");
	if (_isnumber(arg) == 1 && arg != NULL)
	{
		push_arg = atoi(arg);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit_error(*stack);
	}
	add_dnodeint(stack, push_arg);
}

/**
 * _pall - function to print all stack values.
 * @stack: top of the stack
 * @line_number: line number
 *
 * Return: Nothing.
 */
void _pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current;

	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * _isnumber - function check if string is number or not with ascii table
 * @str: string to checks
 *
 * Return: On success 1, otherwise 0.
 */
int _isnumber(char *str)
{
	unsigned int i;

	if (!str)
		return (0);

	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * exit_error - function to freed memory
 * @stack: pointer at the top
 *
 */
void exit_error(stack_t *stack)
{

	if (stack != NULL)
		free_dlistint(stack);
	exit(EXIT_FAILURE);
}
