#include"main.h"
/**
 * print_alphabet_x10 - prints alphabets ten times
 *
 * Return: 0 on successful execution
 */
void print_alphabet_x10(void)
{
	char i;
	char n;

	for (n = 0; n < 10; n++)
	{
		for (i = 'a'; i <= 'z'; i++)
		{
			_putchar(i);
		}
		_putchar('\n');
	}
}
