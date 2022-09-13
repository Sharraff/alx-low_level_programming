#include "main.h"
#include <stdlib.h>
/**
 * main - prints the word _putchar
 *
 * Return: 0 on successfull execution
 */
int main(void)
{
	char word[10] = "_putchar";
	int i = 0;

	for (i = 0; i < 10; i++)
	{
		_putchar(word[i]);
		i++;
	}
	_putchar(10);
	return (0);
}
