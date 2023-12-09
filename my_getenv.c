#include "shell.h"

/*
 * @_getenv: function to locate the path variable
 * @path: var path to be accessed
 *
 * return: 0 on sucess
 *
 * */

char **_getenv(const char*path)
{
	extern char **environ;
	int loop, i;
	i = _strlen(path);
	for(i = 0; environ[i]; i++)
		{
			if(_strncmp(path, environ[i], loop) == 0)
			return(&environ[i]);
		}
	return (NULL);
}
