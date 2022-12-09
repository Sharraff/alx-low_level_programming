#include "lists.h"
/**
 * sum_dlistint - funtion that sums the element of a list
 * @head: head of list to sum
 * Return: sum of all elements
 */
int sum_dlistint(dlistint_t *head)
{

	int count = 0;


	if (head == NULL)
		return (0);
	while (head)
	{
		count += head->n;
		head = head->next;
	}
	return (count);
}
