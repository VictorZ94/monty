#include "monty.h"

/**
 * add_dnodeint - add node at beginning of the nodes.
 * @head: Pointer at top of the nodes
 * @n: Number that contains the node
 * Return: Pointer to a new node.
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *NewNode;

	NewNode = malloc(sizeof(stack_t));
	if (!NewNode)
		return (NULL);

	NewNode->n = n;
	if ((*head) != NULL)
		(*head)->prev = NewNode;
	NewNode->next = *head;
	NewNode->prev = NULL;
	*head = NewNode;

	return (NewNode);
}

/**
 * free_dlistint - freed memory allocation.
 * @head: Pointer at top of the nodes
 *
 * Return: void
 */
void free_dlistint(stack_t *head)
{
	if (head == NULL)
		return;

	free_dlistint(head->next);
	free(head);
}

/**
 * dlistint_len - return numbers of nodes.
 * @h: pointer to head
 *
 * Return: Always EXIT_SUCCESS.
 */
size_t dlistint_len(const stack_t *h)
{
	if (h == NULL)
		return (0);

	return (1 + (dlistint_len(h->next)));
}

/**
 * delete_dnodeint_at_index - Insert node at the index.
 * @head: Pointer at top of the nodes
 * @index: position to free
 * Return: On succes 1 otherwise -1.
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *current;
	stack_t *temp;

	if (!*head)
		return (-1);

	current = *head;
	if (index == 0)
	{
		(*head) = (*head)->next;
		if ((*head))
			(*head)->prev = NULL;
		free(current);
		return (1);
	}
	while (current && --index)
	{
		current = current->next;
		if (current == NULL)
			return (-1);
	}
	temp = current->next;
	current->next = temp->next;
	temp->next->prev = current;
	free(temp);
	return (1);
}
