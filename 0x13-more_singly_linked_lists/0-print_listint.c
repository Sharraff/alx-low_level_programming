#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 *print_listint - function that prints the elements of a linked list
 *
 *@h: head of list
 *Return: number of elements.
 */
size_t print_listint(const listint_t *h)
{
	unsigned int nodes = 0;

	while (h != NULL)
	{


		printf("%d\n", h->n);

		h = h->next;
		nodes++;
	}
	return (nodes);
}
