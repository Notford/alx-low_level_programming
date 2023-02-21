#include "main.h"
#include <stdio.h>

/**
 * print_t_98 - count to 98
 * @n: input number to check
 * return: nothing
 */

void print_to_98(int n)
{
	if (n < 98)
	{
		for (; n < 98; n++)
		{
			printf("%d, ", n);
		}
	}
	if (n == 98)
	{
		printf("%d\n", n);
	}
}
