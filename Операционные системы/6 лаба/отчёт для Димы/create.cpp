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
errno = 0;
	f=fopen("Spravka.dat","wb");
	printf("\n Ввод информации об маршруте: \n");
	 for(int j=0;j<10;j++)
		{
		 printf("\nНазвание начального пункта: "); scanf("%s", t.nPunkt);
		 printf("Название конечного пункта: "); scanf("%s", t.kPunkt);
		 printf("Номер маршрута: "); scanf("%d", &t.nomer);
		 fwrite(&t, sizeof(t), 1, f);
		}
	 fclose(f);
	 if(errno != 0)
		{
			perror("Произошла ошибка");
			printf("Учётное имя: DimaK\nГруппа: ИА-832\n");	
			return(-1);
		}

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
		 printf("\nНомер машрута:%3d \nНазвание начального пункта:%s \nНазвание конечного пункта:%s\n",t.nomer, t.nPunkt, t.kPunkt);
		 fread(&t, sizeof(t), 1, f);
		if(errno != 0)
						{
							perror("Произошла ошибка");
							printf("Учётное имя: DimaK\nГруппа: ИА-832\n");	
							return(-1);
						} 
		}
	 fclose(f);
	 if(errno != 0)
			{
				perror("Произошла ошибка");
				printf("Учётное имя: DimaK\nГруппа: ИА-832\n");	
				return(-1);
			}
return 0;
}
