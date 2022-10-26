#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 *
 *
 *
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{

	listint_t *node = (*head);
	unsigned int i = 0;
	listint_t *node1 = malloc(sizeof(listint_t));
	
	if (node == NULL)
		return (NULL);
	if (*head == NULL)
	{
		*head = node;
		node->next = NULL;
		node->n = n;
		return (node);

	if (idx == 0)
	{
		node->next = *head;
		node->n = n;
		*head = node;
		return (node);
	}
	node1 = *head; 

	for (i = 0; i < idx; i++)
	{
		node = node->next;
	}
	node->n = n;
	node->next = node1->next;
	node1->next = node;

	return (node);
}
