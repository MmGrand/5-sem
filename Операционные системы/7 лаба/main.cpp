#include "main.h"

void p1_1()
{
	for (int i = 0; i < 10; i ++)
		if (environ[i] != NULL)
			printf("environ[%d] : %s\n",i, environ[i]);
}

void p1_2()
{
	char *term, *home, *shell, *user, *pwd, *path;
	term = getenv("TERM");
	home = getenv("HOME");
	shell = getenv("SHELL");
	user = getenv("USER");
	pwd = getenv("PWD");
	path = getenv("PATH");

printf("TERM=%s.\nHOME=%s.\nSHELL=%s.\nUSER=%s.\nPWD=%s.\nPATH=%s.\n", term, home, shell, user, pwd, path);
}

int p3(const char* filename){
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
		p3(optarg);
		break;
		}
		case '?':{
			printf("Неверная опция");
		break;
		}
		case '1':{
			p1_1();
		break;
		}
		case '2':{
			p1_2();
		break;
		}
		default:{
			printf ("Произошла проблема\n");
		break;
		}

	}
	break;
}
printf ("Зарубин Максим Евгеньевич, maximz\n");
exit (0);

}
