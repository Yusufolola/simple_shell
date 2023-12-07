#include "shell.h"
/**
 *
 *
 *
 */


int main(int argc, char *argv[])
{	

	(void)argc, (void)argv;
	size_t amt = 0 ;
	char *buffer = NULL;
	ssize_t amt_read;

	while(1)
	{
	write(STDOUT_FILENO, "ENTER $ ", 8);
	amt_read = getline(&buffer, &amt, stdin);
	if (amt_read == -1)
	{
		perror("Error reading input");
			exit(1);
	}
	}
	free(buffer);
	return(0);
	
}
