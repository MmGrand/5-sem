#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>

#define FIFO "fifo.l"
#define MAXBUFF 80
#define FILENAME "FILENAME~"
#define FNBEGIN 9

typedef struct stud
 { int group;
 char name[10];
 int A[3]; } stud;
stud t; 

int fd;

void Processfile(char *filename, char *newfile);
void Printnewfile(char *filename);
