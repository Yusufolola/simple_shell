#include "shell.h"
/**
 * path_builder - helps build the path to the executable
 * @path: the full path from the environment
 * @command: user input to be executed
 * Return: executable path
 */

char *path_builder(char *path, char *command)
{	char *token, *path_copy;
	struct stat buffer;
	char *file_path = NULL;

	path_copy =  _strdup(path);
	token = strtok(path_copy, ":");

	while (token)
	{
		if (file_path)
		{	free(file_path);
			file_path = NULL;
		}
		file_path = malloc(_strlen(token) + _strlen(command) + 2);
		if (!file_path)
		{	perror("fail to allocate memory for container");
			exit(EXIT_FAILURE);
		}
	      _strcpy(file_path, token);
	      _strcat(file_path, "/");
	      _strcat(file_path, command);
	      _strcat(file_path, "\0");
		if (stat(file_path, &buffer) == 0)
		{	free(path_copy);
			return (file_path);
		}
		else
		{	token = strtok(NULL, ":");
		}
	}
	free(path_copy);
	if (stat(command, &buffer) == 0)
	{	return (command);
	}
	return (NULL);
}
