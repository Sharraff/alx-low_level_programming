#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *pop_listint - A function that deletes the head node of a list
 *and returns the head nodes data
 *@head: A pointer to listint_t struct
 *Return: the head node's data from deleted node.
 */
int pop_listint(listint_t **head)
{
	listint_t *node;
	int n;

	if (*head == NULL)
	{
		return (0);
	}
	n = (*head)->n;
	node = (*head)->next;
	free(*head);
	*head = node;
	return (n);
}
