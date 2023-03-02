#include <stdio.h>
#include <string.h>

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = strlen(n1);
	int len2 = strlen(n2);
	int max_len = len1 > len2 ? len1 : len2;
	int carry = 0;
	int i, sum;

	if (max_len + 1 > size_r)
	{
	return 0;
	}

	r[max_len + 1] = '\0';

	for (i = 0; i < max_len; i++)
	{
	sum = carry;
	if (i < len1)
	{
		sum += n1[len1 - i - 1] - '0';
	}
	if (i < len2)
	{
		sum += n2[len2 - i - 1] - '0';
	}
	r[max_len - i] = sum % 10 + '0';
	carry = sum / 10;
	}

	if (carry)
	{
		r[0] = carry + '0';
		return r;
	}
	else
	{

	return r + 1;
	}
}
