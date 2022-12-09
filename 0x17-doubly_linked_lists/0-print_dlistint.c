#include "lists.h"
#include <stdio.h>
/**
 * print_dlistint - function thhat prints the elements of a linked list
 * @h: head of list
 * Return: number of elements
 */
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *node = h;
	int count = 0;



	if (node == NULL)
		return (0);

	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
		count++;
	}
	return (count);
}
