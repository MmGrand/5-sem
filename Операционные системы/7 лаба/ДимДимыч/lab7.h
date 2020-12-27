#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
extern char **environ;
char *term, *home, *shell, *user, *pwd, *path;
void print1();
void print2();
int file(const char* filename);
