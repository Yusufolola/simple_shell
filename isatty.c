#include "shell.h"
/**
 * main -this confirms the mode our shell is called
 * it takes no parameter
 *
 * Return: 0 if successful
 */

int main (void)
{	
	if(isatty(STDIN_FILENO)== 1)
	{
   	 interact();
	}
	else
	{
	 no_interaction();
	}
	return (0);
}
