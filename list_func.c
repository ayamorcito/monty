#include "monty.h"

/**
  * add_dnodeint - adds a new node at the beginning of a dlistint_t list.
  * @head: head of list
  * @n: where to place node
  *
  * Return: the address of the new element, or NULL if it failed
  */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *nnode = NULL;

	nnode = malloc(sizeof(stack_t));
	if (nnode == NULL)
	{
		fprinf(stderr, "Error: malloc failed\n");
		error_exit(stack);
	}


	nnode->n = n;
	if (*head)
	{
		nnode->next = *head;
		nnode->prev = (*head)->prev;
		(*head)->prev = nnode;
		*head = nnode;
		return (*head);
	}

	nnode->next = *head;
	nnode->prev = NULL;
	*head = nnode;
	return (*head);
}

/**
  * add_dnodeint_end - adds a new node at the end of a dlistint_t list
  * @head: head of the list
  * @n: where to place the new node
  *
  * Return: adds a new node at the end of a dlistint_t list
  */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *nnode = NULL, *now = NULL;

	nnode = malloc(sizeof(stack_t));
	
	if (nnode == NULL)
        {
		fprinf(stderr, "Error: malloc failed\n");
		error_exit(stack);
        }

	nnode->n = n;
	if (*head)
	{
		now = *head;
		while (now->next != NULL)
			now = now->next;

		nnode->next = NULL;
		nnode->prev = now;
		now->next = nnode;
		return (nnode);
	}

	nnode->next = *head;
	nnode->prev = NULL;
	*head = nnode;
	return (*head);
}

/**
 * delete_dnodeint_at_index - delete node a specific spot
 * @head: pointer to first node on list
 * @index: position to delete
 * Return: 1 if successful, -1 if failure
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *tmp;
	stack_t *tmp2;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	tmp = *head;

	if (index == 0)
	{
		*head = tmp->next;
		if (tmp->next != NULL)
			tmp->next->prev = NULL;
		free(tmp);
		return (1);
	}
	i = 0;
	while (i < (index - 1))
	{
		if (tmp == NULL)
			return (-1);
		tmp = tmp->next;
		i++;
	}
	tmp2 = (tmp->next)->next;
	if (tmp->next->next != NULL)
		tmp->next->next->prev = tmp;
	free(tmp->next);
	tmp->next = tmp2;

	return (1);
}

/**
  * free_dlistint - frees a dlistint_t list.
  * @head: head of the list
  *
  *
  */
void free_stack(stack_t *head)
{
	stack_t *now = head, *next = NULL;

	while (now != NULL)
	{
		next = now->next;
		free(now);
		now = next;
	}
}
