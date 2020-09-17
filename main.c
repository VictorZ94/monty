#include "monty.h"

/**
 * main - Enter point interpreter monty code scripting
 * @argc: count number arguments
 * @argv: array of pointer to each string
 *
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	stack_t *stack;

	stack = NULL;
	while (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	read_file(&stack, argv[1]);
	free_dlistint(stack);
	return (0);
}

/**
 * read_file - function reads every function of the stack
 * @stack: top of the stack
 * @filename: file descriptor to read monty Bytecode
 *
 * Return: Nothing
 */
void read_file(stack_t **stack, char *filename)
{
	size_t len; /* for getline */
	ssize_t read = 0; /*  for getline */
	char *line = NULL;  /*  for getline */
	FILE *fd;  /*File descriptor */
	char *token = NULL;
	int line_number = 1;
	instruct_func func; /* This contain all pointer function */

	fd = fopen(filename, "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, fd)) != EOF)
	{
		token = strtok(line, "\n ");
		if (token == NULL)
		{
			line_number++;
			continue;
		}
		func = get_op_func(token);
		if (!func)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, line);
			free(line);
			fclose(fd);
			exit_error(*stack);
		}
		func(stack, line_number);
		line_number++;
	}
	fclose(fd);
	free(line);
}
