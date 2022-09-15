#include "main.h"
/**
 *print_sign - main function
 *
 *@n: character to compare
 *Return: + if positive, - if negative
 */
int print_sign(int n)
{

	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n < 0)
	{
		_putchar('-');
		return (-1);
	}
	else
	{
		_putchar('0');
		return (0);
	}
}
