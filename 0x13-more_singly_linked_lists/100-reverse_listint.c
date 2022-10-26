#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * reverse_listint - function that reverses a tree
 * @head: pointer to list.
 * Return: A pointer to the first node of the reverse list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *new = NULL;
	listint_t *q;

	if (*head == NULL)
	{
		return (NULL);
	}
	while (*head)
	{
		q = (*head)->next;
		(*head)->next = new;
		new = *head;
		*head = q;
	}
	*head = new;
	return (*head);
}
