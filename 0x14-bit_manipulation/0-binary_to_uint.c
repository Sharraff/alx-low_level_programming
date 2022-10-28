#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 *binary_to_uint - A function that converts a binary to an unsigned int
 *@b: A pointer to binary string
 *
 *Return: unsigned integer converted number
 */
unsigned int binary_to_uint(const char *b)
{

	unsigned int dec = 0;
	unsigned int base = 1;
	unsigned int len = 0;


	if (b == NULL)
		return (0);
	while (b[len])
		len++;

	while (len)
	{
		if (b[len - 1] != '0' && b[len - 1] != '1')
			return (0);
		if (b[len - 1] == '1')
			dec += base;
		base *= 2;
		len--;
	}
	return (dec);
}
