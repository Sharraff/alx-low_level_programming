#include "main.h"
/**
*times_table - It prints 9 times table starting with 0
*
*Return: 0 0n successfull execution
*/
void times_table(void)
{
	int x = 0;
	int y;
	int z;

	while (x < 0)
	{
		y = 0;

		while (y < 0)
		{
			z = x * y;

			if (z > 9)
			{
				_putchar((z / 10) + '0');
				_putchar((z % 10) + '0');
			}
			else if (y != 0)
			{
				_putchar(' ');
				_putchar(z + '0');
			}
			else
			{
				_putchar(z + '0');
			}
			if (y != 9)
			{
				_putchar(',');
				_putchar(' ');
			}
			y++;
		}
		_putchar('\n');
		x++;
	}
}
