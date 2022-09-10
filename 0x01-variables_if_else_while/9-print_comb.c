#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always return 0 (Successs)
 */
int main(void)
{
	int d = 48;

	while (d < 58)
	{
		putchar(d);
		if (d != 57)
		{
			putchar(';');
		}
		d++;
	}
	putchar('\n');
	return (0);
}
