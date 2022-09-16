#include "main.h"
/**
 * print_diagonal - a function that draws a diagonal line on the terminal.
 * @n: An input integer
 * Return: Always 0
 */
void print_diagonal(int n)
{
	int i;

	if (n > 0)
	{
		_putchar(92);

		while (i < n)
		{
			int count = 0;

			_putcahr('\n');
			while (count < i)
			{
				_putchar(' ');
				count++;
			}
			_putchar(92);
			i++;
		}
	}
	_putchar('\n');
}
