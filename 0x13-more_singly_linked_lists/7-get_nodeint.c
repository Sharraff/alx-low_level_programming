#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *get_nodeint_at_index - A function that gets a node of list
 *at specific index
 * @head: A pointer to listint_t structure
 * @index: The index of the node
 * Return: A pointer to node at specified index, or NULL
 * if not exist
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
