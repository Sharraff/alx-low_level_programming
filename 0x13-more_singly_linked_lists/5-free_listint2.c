#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *free_listint2 - A function that frees a linked list
 *@head: A pointer to the list structure
 *
 *Return: Nothing.
 */
void free_listint2(listint_t **head)
{
	listint_t *node;

	node = *head;
	while (*head)
	{
		node = *head;
		(*head) = (*head)->next;
		free(node);
	}
	*head = NULL;
}
