#include "lists.h"
/**
 * dlistint_len - counts the numer of elements in a list
 * @h: head of list
 * Return: number of elements in a list
 */

size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *tmp = h;
	int count = 0;


	while (tmp != NULL)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}
