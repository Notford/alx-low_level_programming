#include "main.h"
/**
 * print_alphabet_x10 = prints out alphabet in lowercase
 * main - uses built in function 
 * return : 0 if successful
 */

void print_alphabet_x10(void)
{
	int l;
	int n = 0;

	while (n < 10)
	{
		l = 'a';
		while (l <= 'z')
		{
			_putchar(l);
			l += 1;
		}
		_putchar(10);
		n += 1;
	}
}
