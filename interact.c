#include "shell.h"
/**
 * interact - this is the mode when the file descriptor is
 * 1 and it means it will get inputs from the user
 * Returns: void/nothing
 */
void interact(void)
{
	char *line, **args;
	int status = -1;

	do {
		/* print the prompt*/
		gimme_com();
		/* read the input and save it in 'line' */
		line = read_input();
		/* tokenize the input save it in 'args' */
		args = tok_line(line);
		/* use the return of the execve to know if successful*/
		status = args_exec(args);
		free(line);
		free(args);
		if (status >= 0)
		{
			exit(status);
		} while (status == -1);
	}
}
