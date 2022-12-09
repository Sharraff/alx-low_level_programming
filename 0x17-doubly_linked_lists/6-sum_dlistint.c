#include "lists.h"
/**
 * sum_dlistint - funtion that sums the element of a list
 * @head: head of list to sum
 * Return: sum of all elements
 */
int sum_dlistint(dlistint_t *head)
{

	dlistint_t *tmp = head;
	int count = 0;


	if (tmp == NULL)
		return (0);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		count += tmp->n;
	}
	return (count);
}
