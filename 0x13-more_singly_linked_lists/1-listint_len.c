#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
/**
 *listint_len - function that counts the number of elements in a list.
 *@h: head of list
 *Return: number of elements inlist.
 */
size_t listint_len(const listint_t *h)
{
	unsigned int nodes = 0;

	while (h != NULL)
	{
		h = h->next;
		nodes++;
	}
	return (nodes);
}
