#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - entry point for the program
 *
 * This function generates random valid passwords for the 101-crackme program.
 * It takes no arguments.
 *
 * Return: 0 on success, non-zero on failure
 */

int main(void)
{
	int pass[100];
	int i, sum, n;

	sum = 0;
	srand(time(NULL));

	for (i = 0; i < 100; i++)
	{
		pass[i] = rand() % 78;
		sum += (pass[i] + '0');
		putchar(pass[i] + '0');
		if ((2772 - sum) - '0' < 78)
		{
			n = 2772 - sum - '0';
			sum += n;
			putchar(n + '0');
			break;
		}
	}

	return (0);
}

