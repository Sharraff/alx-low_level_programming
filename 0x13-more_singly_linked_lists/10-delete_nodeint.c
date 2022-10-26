#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *
 *
 *
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *previous = *head;
	listint_t *current = *head;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);
	else if(index == 1)
	{
		*head = current->next;
		free(current);

	}
	else
	{
		for (i = 0; i < (index - 1); i--)
		{
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
		current = NULL;
		free(current);

	}
	return (1);
}
