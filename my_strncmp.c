#include "shell.h"

/*
 * _strncmp - Compare two strings.
 * @str1: Pointer to a string.
 * @str2: Pointer to a string.
 * @n: The first n bytes of the strings to compare.
 *
 * Return: Less than 0 if str1 is shorter than str2.
 *         0 if str1 and str2 match.
 *         Greater than 0 if str1 is longer than str2.
 */

int _strncmp(const char *str1, const char *str2, size_t a)
{
	size_t i;

	for (i = 0; str1[i] && str2[i] && i < a; i++)
	{
		if (str1[i] > str2[i])
			return (str1[i] - str2[i]);
		else if (str1[i] < str2[i])
			return (str1[i] - str2[i]);
	}
	if (i ==a)
		return (0);
	else
		return (-15);
}

