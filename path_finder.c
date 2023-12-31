#include "shell.h"
/**
 * path_finder - help get the absolute path to the input command
 * @command: this is the inputed command
 * Return: the absolute path for the execve
 */

char *path_finder(char *command)
{
/*	char *abs_path; */
	char *abs_path;
	char *path = getenv("PATH");
/*	 char **path;*/
/*	path = _getenv("PATH");*/

	if (!path)
	{
		perror("cant locate path");
		return (NULL);
	}

	if (command == NULL)
		return (NULL);
/*	abs_path = path_builder((char *)path, command);*/
	abs_path = path_builder(path, command); 

	if (abs_path == NULL)
	{
		perror("command not found");
		return (NULL);
	}
	return (abs_path);
}
