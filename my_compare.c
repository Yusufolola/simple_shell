#include "shell.h"
/**
 * _strcmp - compare string value
 * @s1: input value
 * @s2: input value
 * Return: s1[i] - s2[i]
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

/**
 * _strncmp - Compare two stringd
 * @str1: Pointer to a string
 * @str2: Pointer to a string
 * @a: The first n bytes to the strings to compare
 *
 * Return: less than 0 if str1 is less than str2.
 * 0 if str1 and str2 match
 * Greater than 0 if str1 is longer than str2.
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
	if (i == a)
		return (0);
	else
		return (-15);
}
