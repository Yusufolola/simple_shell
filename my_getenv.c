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
	i = _strlen((char*)path);
	for(loop = 0; loop <= i; loop++)
		{
			if(_strcmp((char*)path, environ[i]) == 0)
			return(&environ[i]);
		}
	return (NULL);
}
