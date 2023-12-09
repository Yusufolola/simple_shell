#include "shell.h"

/**
  * ObtainFileRoute - obtain the complete path of the file
  * @address: Argument name
  *
  * Return: The full path argument to the file
  */

char *ObtainFileRoute(char *address)
{
	char *complete_route;
	char *route = _getenv("ROUTE");

	if (!route)
	{
		perror("route invalid");
		return (NULL);
	}	

	complete_route = search_file(route, address);
	if (complete_route == NULL)
	{
		perror("Complete path inaccessible");
		return (NULL);
	}
	return (complete_route);
}

/**
 * search_file - Obtain the executable route of the file
 * @path: complete route path
 * @address: The executable file
 *
 * Return: The complete route to the executable
 */

char *search_file(char *route, char*address)
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
	route_buf = malloc(_strlen(token) + _strlen(address) + 2);
	if (!route_buf)
	{

	perror("failed: memory allocation unsuccesful");
	exit(EXIT_FAILURE);
	}
	_strcpy(route_buf, token);
	_strcat(route_buf, "/");
	_strcat(route_buf, address);
	_strcat(route_buf, "\0");

	if (stat(route_buf, &route_path) == 0 && access(route_buf, X_OK == 0)
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
