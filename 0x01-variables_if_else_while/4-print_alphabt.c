#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - entry point
 *
 * Return: Always return 0 (Success)
 *
 */
int main(void)
{
	char a;

	for (a = 'a'; a <= 'z'; a++)
	{
		if (a == 'q' || a == 'e')
		{
			continue;
		}
		putchar(a);
	}
	putchar('\n');
	return (0);
}
