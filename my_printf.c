/*
 * @print_code: function for printing code in place of printf
 * @receive: string of character to be assed to the function
 *
 * */


#include "shell.h"

void print_code(const char *receive)
{
	write(STDOUT_FILENO, &receive, _strlen((char*)receive));
}

