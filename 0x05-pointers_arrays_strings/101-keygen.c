#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define PASSWORD_LENGTH 12
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
	char password[PASSWORD_LENGTH + 1];
	const char *charset = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const size_t charset_len = strlen(charset);

	srand(time(NULL));

	for (size_t i = 0; i < PASSWORD_LENGTH; i++)
	{
	password[i] = charset[rand() % charset_len];
	}

	password[PASSWORD_LENGTH] = '\0';

	printf("Generated password: %s\n", password);

	return (0);
}

