#include "shell.h"

/*
 * _strtok - function to tokenise a string
 * @in: string to characters to be splited
 * @deli: string separator
 */

char* _strtok(char *in, char deli)
{	char *split;
	static char *new = NULL;
	if (in != NULL) 
	{
	new = in;

	}
	
	if (new == NULL || *new == '\0')
	{
	return (NULL);
	}
	split = new;

	while (*new != '\0')

	{
	if (*new == deli)
	{
	*new = '\0';
	new++;
	return (split);
	}
	new++;
	}
	return (split);
}
