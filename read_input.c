#include "shell.h"
/**
 * read_input - this collect and save the user inputs
 *
 * Return:it returns pointer to address where inputs are stored
 */

char *read_input(void)
{
	char *line = NULL;
	size_t buf = 0;

	if (getline(&line, &buf, stdin) == -1)
	{	
		if (feof(stdin))
		{
			free (line);
			exit(successful_exit);
		}
		else
		{
			free(line);
			perror("error while reading line from stdin");
			exit(failed);
		}
	}
	return (line);
}
