#include "shell.h"

/** main - Main access to our shell program
 * @argc: Argument count to the main function
 * @argv: Pointer to array of argument values
 *
 * Return: 0 Always when succesful
 */


int main(int argc, char *argv[])
{	

	(void)argc, (void)argv;
	size_t amt = 0 ;
	char *token,*buffer = NULL;
	ssize_t amt_read;
	pid new_pid;
	int result;
	char **array;
	int i;

	while(true)
	{
	write(STDOUT_FILENO, "ENTER $ ", 8);
	amt_read = getline(&buffer, &amt, stdin);
	if (amt_read == -1) || (amt_read == EOF)
	{
		break;
	}
	else if 
		(_strcmp(buffer,"exit")== 0)
		{
			free(buffer);
			exit(0);
		}
	token = strtok(buffer , "\n");

	array = malloc(sizeof(char*) * 1024;
	int i = 0
	while (token)
	{
		array[i] = token;
		token = strtok(NULL, "\n");
		i++;
	}
	
	array[i] = NULL;
	new_pid = fork();
	if (new_pid == -1)
	{
		perror("duplicate child failed");
		exit (1);
	}
	if (new_pid == 0)
	{
	/*duplicate process valid, user input can be executed */
	print_code("Process creation valid\n");
	}
	else
	{
		/*child process run before ending the parent processs */
	wait(&result);	
	}
	
	
	free(buffer);
	return(0);
	
}