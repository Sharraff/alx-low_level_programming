#include <stdio.h>

/**
 * main - prints numbers from 1 to 100 followed by a new line and replaces
 * Fizz, Buzz or FizzBuzz if the number is a multiple of 3, 5
 *
 * Return: 0
 */
int main(void)
{
	int i;

	if (i % 3 == 0 || i % 5 == 0)
	{
		if (i % 3 == 0)
		{
			printf('Fizz');
		}
		if (i % 5 == 0)
		{
			printf('Buzz');
		}
		else
		{
			printf("%d", i);
		}
		if (i != 100)
		{
			printf(' ');
		}
		printf('\n');
		return (0);
	}
}
