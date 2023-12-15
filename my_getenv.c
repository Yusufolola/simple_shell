#include "shell.h"
/**
 * _getenv - Get an environment variable from the PATH.
 * @name: The name of the environmental variable to access
 *
 * Return: If the environmental var does not exist return - NULL.
 * Otherwise a pointer to the environmental variable
 */

char **_getenv(const char *name)
{
	int num, count;

	count = _strlen(name);
	for (num = 0; environ[num]; num++)
	{
		if (_strncmp(name, environ[num], count) == 0)
			return (&environ[num]);
	}
	return (NULL);
}
