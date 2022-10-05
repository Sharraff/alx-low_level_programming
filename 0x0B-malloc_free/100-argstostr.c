#include "main.h"
#include <stdlib.h>

/**
 * argstorstr - concatenates all arguments of the pogram.
 * @ac: argument count.
 * @av: array of arguments
 * Return: char value
 */
char *argstorstr(int ac, char **av)
{
	int i;
	int j;
	int k;
	int size;
	char *arg;

	size = 0;
	k = 0;
	if (ac == 0 || av == 0)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			size++;
			i++;
		}
	}
	arg = malloc((sizeof(char) * size) + 1);
	if (arg == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			arg[k] = av[i][j];
			j++;
			k++;
		}
		arg[k] = '\n';
		k++;
		i++;
	}
	arg[k] = '\0';
	return (arg);
}
