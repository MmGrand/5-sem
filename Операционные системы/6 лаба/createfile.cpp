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
	f=fopen("Wedomost.dat","wb");
	printf("\n Ввод информации об студенте: \n");
	 for(int j=0;j<10;j++)
		{
		 printf("\nФамилия и инициалы: "); scanf("%s", t.name);
		 printf("Номер группы: "); scanf("%d", &t.group);
		 printf("Успеваемость по трём предметам: "); 
		 for(int i=0;i<3;i++)
		 	scanf("%d", &t.A[i]);
		 fwrite(&t, sizeof(t), 1, f);
		}
	 fclose(f);
	 if(errno != 0)
		{
			perror("Произошла ошибка");
			printf("Учётное имя: maximz\nГруппа: ИА-831\n");	
			return(-1);
		}

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
		 printf("\nГруппа:%3d \nФамилия и инициалы:%s\n",t.group, t.name);
		 for(int i=0;i<3;i++)
		 	printf("%d\t",t.A[i]);
		 printf("\n");
		 fread(&t, sizeof(t), 1, f);
		if(errno != 0)
						{
							perror("Произошла ошибка");
							printf("Учётное имя: maximz\nГруппа: ИА-831\n");	
							return(-1);
						} 
		}
	 fclose(f);
	 if(errno != 0)
			{
				perror("Произошла ошибка");
				printf("Учётное имя: maximz\nГруппа: ИА-831\n");	
				return(-1);
			}
return 0;
}
