#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
/**
 *
 *
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *node;
	int len = 0;

	node = malloc(sizeof(listint_t));
	if (node == NULL)
	{
		return (NULL);
	}
	
	node->n = n;
	node->next = *head;
	*head = node;
	return (node);
}
