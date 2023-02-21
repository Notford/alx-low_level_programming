#include "main.h"

/**
 * _abs - function that computes the absolute value of an integer
 * @x: the input number to check
 * return: int
 */

int _abs(int x)
{
	if (x < 0)
	{
		x = x * (-1);
		return (x);
	}
	else
		return (x);
}
