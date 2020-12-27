#include "lab7.h"

void print1()
{
	for (int i = 2; i < 12; i ++)
		if (environ[i] != NULL)
			printf("environ[%d] : %s\n",i-2, environ[i]);
}

void print2()
{
user = getenv("USER");
pwd = getenv("PWD");
path = getenv("PATH");
term = getenv("TERM");
home = getenv("HOME");
shell = getenv("SHELL");
printf("TERM=%s.\nHOME=%s.\nSHELL=%s.\nUSER=%s.\nPWD=%s.\nPATH=%s.\n", term, home, shell, user, pwd, path);
}

int file(const char* filename){
    int ch;
    FILE *file = fopen(filename, "r");
    while (!feof(file) && !ferror(file) && file != NULL)
    {
        ch = getc(file);
        if (ch != EOF)
        {
            putchar(ch);
        }
    }
    putchar('\n');

return 0;
}

int main(int argc, char *argv[])
{
int c;


while (1){
	c = getopt(argc, argv, "f:12");

	switch (c){
		case 'f':{
		file(optarg);
		break;
		}
		case '?':{
			printf("Неверная опция");
		break;
		}
		case '1':{
			print1();
		break;
		}
		case '2':{
			print2();
		break;
		}
		default:{
			printf ("Что-то пошло не так\n");
		break;
		}

	}
	break;
}
printf ("Конради Дмитрий Викторович, DimaK\n");
exit (0);

}
