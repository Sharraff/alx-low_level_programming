#include "lists.h"

/**
 *add_dnodeint_end - adds node at end
 * @head: head address of linked list
 * @n: number of new value for new node
 * Return: address of new node or NULL
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{

	dlistint_t *tmp = malloc(sizeof(dlistint_t));
	dlistint_t *tmp1;

	if (tmp == NULL)
		return (NULL);

	tmp->n = n;
	tmp->next = NULL;
	tmp->prev = NULL;
	if (*head == NULL)
	{
		*head = tmp;
		return (tmp);
	}
	else
	{
		tmp1 = *head;
		while (tmp1->next != NULL)
		{
			tmp1 = tmp1->next;
		}
		tmp->prev = tmp1;
		tmp1->next = tmp;
		return (tmp);
	}
}
