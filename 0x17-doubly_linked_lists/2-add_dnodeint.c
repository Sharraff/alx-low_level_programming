#include "lists.h"
/**
 * add_dnodeint - adds a node at the begining of the list
 * @head: head of list
 * @n: input n
 * Return: new node
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *tmp = malloc(sizeof(dlistint_t));

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
	(*head)->prev = tmp;
	tmp->next = *head;
	*head = tmp;

	return (tmp);
}
