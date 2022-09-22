#include "main.h"

/**
 * puts2 - prints every other character of a given string
 * @str: passed string pointer
 *
 * Return: void
 */
void puts2(char *str)
{
	int i = 0;
	int len = 0;


	while (str[len] != '\n')
		len++;
	len -= 1;

	for (; i <= len; i += 2)
		_putchar(str[i]);

	_putchar('\n');
}
