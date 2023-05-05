#include "main.h"

/**
  * set_bit - set a bit at a given index to 1
  * @n: pointer to change
  * @index: index to change to 1
  *
  * Return: 1 if it worked or -1 if an error occurrs
  */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);
	*n = ((1UL << index) | *n);
	return (1);
}
