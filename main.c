#include "shell.h"

/** main - Main access to our shell program
 * @argc: Argument count to the main function
 * @argv: Pointer to array of argument values
 *
 * Return: 0 Always when succesful
 */


int main(int argc, char *argv[])
{	
	size_t amt = 0 ;
	ssize_t amt_read;
	char *token, *buffer = NULL;

/*	(void)argc, (void)argv; */

/*	ssize_t amt_read; */
	pid_t new_pid;
	int result;
	char **array;
	int i;
	char *route;

	(void)**argv;	
	(void)argc;

	while(true)
	{
		if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "ENTER $ ", 8);
		amt_read = getline(&buffer, &amt, stdin);
		if (amt_read == -1)
		{
		break;
		}
		else if (_strcmp(buffer,"exit")== 0)
		{
			free(buffer);
			exit(0);
		}
		token = strtok(buffer , "\n");
		array = malloc(sizeof(char*) * 1024);
		 i = 0;
		while (token)
		{
			array[i] = token;
			token = strtok(NULL, "\n");
			i++;
		}
	
		array[i] = NULL;
		route = ObtainFileRoute(array[0]);
		new_pid = fork();
		if (new_pid == -1)
		{
			perror("duplicate child failed");
			exit (1);
		}
		if (new_pid == 0)
		{
			execve(route,array,NULL);
			/*duplicate process valid, user input can be executed */
			if (execve(route,array,NULL) == -1)
			{
			perror("program failed");
			exit(97);
			}
		}
		else
		{
			/*child process run before ending the parent processs */
			wait(&result);	
		}
	}
	free(route);
	free(buffer);
	return(0);
	
}
