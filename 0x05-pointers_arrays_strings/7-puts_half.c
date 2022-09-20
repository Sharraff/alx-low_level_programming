#include "main.h"
/**
 * puts_half - prints the second half of a given string
 * @str: passed string pointer
 * 
 * Return: void
 */
void puts_half(char *str)
{
	int len = 0, i, n;


	while (str[len] != '0')
		len++;
	if (len % 2 == 0)
		n = len / 2;
	else
		len = (len + 1) / 2;
	while (*(str + len) != '\n')
	{
		for (i = n; i < len; i++)
		_putchar(str[i]);
	}
	_putchar('\n');
}
