#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXBUFF 80
#define PERM 0666
 
typedef struct our_msgbuf
{
    long mtype;
    char buff[MAXBUFF];
}
Message;

void zamena(char *str);
