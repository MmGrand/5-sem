#include "stdio.h"
#include<locale.h>
#include <string.h>
#include <errno.h>
typedef struct stud
 { int group;
 char name[10];
 int A[3]; } stud;
stud t; 
int main()
{
setlocale(0,"Rus"); 
FILE *f;
errno = 0;
int k, l=0;
f=fopen("Wedomost.dat","rb"); 
if(errno != 0)
				{
					perror("Произошла ошибка");
					printf("Учётное имя: maximz\nГруппа: ИА-831\n");	
					return(-1);
				} 
fread(&t, sizeof(t), 1, f); 
while (!feof(f))
{
	k=0;
	for(int i=0;i<3;i++)
		if(t.A[i]==2)
			k++;
	 if(k==1)
	 {
		 printf("\nГруппа:%3d \nФамилия и инициалы:%s\n",t.group, t.name);
		 for(int i=0;i<3;i++)
		 	printf("%d\t",t.A[i]);
		 l++;
	 }
	 fread(&t, sizeof(t), 1, f);
	if(errno != 0)
					{
						perror("Произошла ошибка");
						printf("Учётное имя: maximz\nГруппа: ИА-831\n");	
						return(-1);
					} 
 }
fclose(f);
if(l==0) printf("Таких студентов нет\n");
if(errno != 0)
				{
					perror("Произошла ошибка");
					printf("Учётное имя: maximz\nГруппа: ИА-831\n");	
					return(-1);
				} 
}
