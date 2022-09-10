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

	while (d < 58)
	{
		a = 48;
		while (a < 58)
		{
			if (d != a && d < a)
			{
				putchar(d);
				putchar(a);

				if (!(d == 56 && a == 57))
				{
					putchar(',');
					putchar(' ');
				}
			}
			a++;
		}
		d++;
	}
	putchar('\n');
	return (0);
}
