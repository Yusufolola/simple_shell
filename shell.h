#ifndef SHELL_H
#define SHELL_H
/*Enables us to use most functions*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>


/*This are the prototypes used */
char *search_file(char *route, char*address);
char *ObtainFileRoute(char *address);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
char *_strdup(char *str);
int initial_strok(const char *name);




#endif /* shell_h */
