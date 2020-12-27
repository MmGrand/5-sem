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

typedef struct way
 { int nomer;
 char nPunkt[15];
 char kPunkt[15];} way;
way t; 

int fd;


void DataProcessing(char *filename, char *Search, char *newfile);
void DataPrint(char *filename);
