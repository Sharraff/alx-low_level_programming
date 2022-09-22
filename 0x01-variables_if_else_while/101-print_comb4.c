#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always return 0 (Success)
 */
int main(void)
{
	int d = 48;
	int a = 48;
	int i = 48;

	while (d < 58)
	{
		a = 48;
		while (a < 58)
		{
			i = 48;
			while (i < 58)
			{
				if (d != a && a != i && d < a && a < i)
				{
					putchar(d);
					putchar(a);
					putchar(i);
					if (!(d == 55 && a == 56 && i == 57))
					{
						putchar(',');
						putchar(' ');
					}
				}
				i++;
			}
			a++;
		}
		d++;
	}
	putchar('\n');
	return (0);
}
