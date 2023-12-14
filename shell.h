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
/*char *search_file(char *route, char*name);
char *ObtainFileRoute(char *name);
*/
char *path_finder(char *command);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
char *_strdup(char *str);
int initial_strok(const char *name);
extern char **environ;

char **_getenv(const char*path); 
int _strcmp(char *s1, char *s2);
void print_code(const char *receive);
int _strlen(char *s);
char *path_builder(char *path, char *command);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);





#endif /* shell_h */
