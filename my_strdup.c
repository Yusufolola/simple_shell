#include "shell.h"

/**
 * _strdup - duplicates a string into newly allocated array
 *
 * @str: string to duplicate
 *
 * Return: pointer to new string
 */
char *_strdup(char *str)
{
	int size = 0;
	char *ptr, *ret;

	if (!str)
		return (NULL);

	ptr = str;
	while (*ptr++)
		size++;

	new = malloc(size + 1);
	if (!new)
		return (NULL);

	ptr = new;
	while (*str)
		*ptr++ = *str++;

	*ptr = 0;
	return (new);
}
