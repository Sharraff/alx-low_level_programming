#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 *sum_listint - A function that sums values from listint_t
 *@head: A pointer listint_t structure
 *
 *Return: the sum of elements in a list.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;


	if (head == NULL)
		return (0);

	while (head != NULL)
	{
		sum = sum + head->n;
		head = head->next;
	}
	return (sum);
}
