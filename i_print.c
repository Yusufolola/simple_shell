#include "shell.h"
/**
 * i_print - is a function that print an input
 * @message: this is the pointer to the input
 */
void i_print(const char *message)
{
	write(STDOUT_FILENO, message, strlen(message));
}
