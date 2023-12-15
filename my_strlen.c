#include "shell.h"
/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 */
int _strlen(const char *s)
{
	int longi = 0;

	if (!s)
	return (longi);
	for (longi = 0; s[longi]; longi++)
		;

	return (longi);
}
