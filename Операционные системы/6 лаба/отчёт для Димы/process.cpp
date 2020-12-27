#include "stdio.h"
#include<locale.h>
#include <string.h>
#include <errno.h>
typedef struct way
 { int nomer;
 char nPunkt[15];
 char kPunkt[15];} way;
way t; 
int main()
{
setlocale(0,"Rus"); 
FILE *f;
int k=0;
char Search[15];
errno = 0;
printf("Введите название пункта:"); scanf("%s", Search);
f=fopen("Spravka.dat","rb"); 
if(errno != 0)
				{
					perror("Произошла ошибка");
					printf("Учётное имя: DimaK\nГруппа: ИА-832\n");	
					return(-1);
				} 
fread(&t, sizeof(t), 1, f); 
while (!feof(f))
{
	if(strcmp(Search,t.nPunkt)==0 || strcmp(Search,t.kPunkt)==0)
	 {
		printf("\nНомер машрута:%3d \nНазвание начального пункта:%s \nНазвание конечного пункта:%s\n",t.nomer, t.nPunkt, t.kPunkt);
		k++;
	 }
	 fread(&t, sizeof(t), 1, f);
	if(errno != 0)
					{
						perror("Произошла ошибка");
						printf("Учётное имя: maximz\nDimaK\nГруппа: ИА-832\n");	
						return(-1);
					} 
 }
fclose(f);
if(k==0) printf("Таких маршрутов нет\n");
if(errno != 0)
				{
					perror("Произошла ошибка");
					printf("Учётное имя: DimaK\nГруппа: ИА-832\n");	
					return(-1);
				} 
}
