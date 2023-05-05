#include "main.h"

/**
  * set_bit - set the value of bit to 1 at a given index
  * @n: pointer to change
  * @index: index to change to 1
  * Returns: 1 if it worked or -1 if an error occurrs
  */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);
	*n = ((1UL << index) | *n);
	return (1);
}
