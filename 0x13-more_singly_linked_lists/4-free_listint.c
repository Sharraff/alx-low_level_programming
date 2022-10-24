#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *free_listint - A function that frees a linked list
 *@head: A pointer to the list structure
 *
 *Return: Nothing.
 */
void free_listint(listint_t *head)
{
	listint_t *node;

	while (head)
	{
		node = head;
		head = head->next;
		free(node);
	}
	free(head);
}
