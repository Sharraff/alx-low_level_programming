#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *
 *
 *
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;

	
	if (head == NULL)
		return (NULL);

	for (i = 0; i < index; i++)
	{
		head = head->next;
	}
	return (head);
}
