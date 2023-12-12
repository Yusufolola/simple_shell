#include "shell.h"

/**
 * initial_strok - Check if the file begins with slash
 * @name: The filename to be checked
 *
 * Return: 0 if true and 1 is false
 */

int initial_strok(const char *name)
{

	if (name != NULL && name[0] == '/')
	return (0);
	else
	return (1);
}


/**
 * search_file - Obtain the executable route of the file
 * @path: complete route path
 * @name: The executable file
 *
 * Return: The complete route to the executable
 */

char *search_file(char *route, char*name)
{
	char *route_dup, *token;
	struct stat route_path;
	char *route_buf = NULL;

	route_dup = _strdup(route);
	token = strtok(route_dup, ":");

	while (token)
	{
		if (route_buf)
		{
			free(route_buf);
			route_buf = NULL;
		}
		route_buf = malloc(_strlen(token) + _strlen(name) + 2);
		if (!route_buf)
		{

			perror("failed: memory allocation unsuccesful");
			exit(EXIT_FAILURE);
		}
			_strcpy(route_buf, token);
			_strcat(route_buf, "/");
			_strcat(route_buf, name);
			_strcat(route_buf, "\0");

		if (stat(route_buf, &route_path) == 0 && access(route_buf, F_OK) == 0 && access(route_buf, X_OK) == 0)
		{
			free(route_dup);
			return (route_buf);
		}
			token = strtok(NULL, ":");
	}	
	free(route_dup);
	if (route_buf)
	free(route_buf);
	return (NULL);
}


/**
  * ObtainFileRoute - obtain the complete path of the file
  * @name: Argument name
  *
  * Return: The full path argument to the file
  */

char *ObtainFileRoute(char *name)
{
        char *complete_route;
        char *route = getenv("PATH");
        if (initial_strok(name) && access(name, F_OK) == 0)
        return (_strdup(name));

        if (!route)
        {
                perror("route invalid");
                return (NULL);
        }

        complete_route = search_file(route, name);
        if (complete_route == NULL)
        {
                perror("Complete path inaccessible");
                return (NULL);
        }
        return (complete_route);
}
