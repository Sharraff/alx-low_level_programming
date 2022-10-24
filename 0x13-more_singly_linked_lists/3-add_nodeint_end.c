#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *add_nodeint_end - adds a new node at the end of a listint_t list.
 * @head: pointer to pointer of first element of list.
 * @n: element to be added in the list.
 *
 * Return: address of the new element or NULL if it fails.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *node1;
	listint_t *node2;
	int i = 0;

	node1 = malloc(sizeof(listint_t));

	if (node1 == NULL)
	{
		return (NULL);
	}
	node1->n = n;
	node1->next = NULL;
	/* if head is a null pointer, assign new node to it*/
	if (*head == NULL)
	{
		node1->next = *head;
		*head = node1;
	}

	else
	{
		node1->next = NULL;
		node2 = *head;

		for (i = 0; node2->next != NULL; i++)
		{
			node2 = node2->next;
		}
		node2->next = node1;
	
	}
	return (node1);
}
