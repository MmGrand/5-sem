#include "./lab9.h"

void DataPrint(char *filename){
	FILE *f; int k=0;
	f=fopen(filename,"rb");
	fread(&t, sizeof(t), 1, f); 
while (!feof(f))
{
	printf("\nНомер машрута:%3d \nНазвание начального пункта:%s \nНазвание конечного пункта:%s\n",t.nomer, t.nPunkt, t.kPunkt);
	k++;
	fread(&t, sizeof(t), 1, f);
}
if(k==0) printf("Таких маршрутов нет\n");
fclose(f);
				}

int main(int argc, char *argv[]){
	char filename[MAXBUFF], newname[MAXBUFF];
	int n;
	char Search[15]; 
    	char *buff = (char *)calloc(MAXBUFF, sizeof(char)); 
	if((fd = open(FIFO, O_WRONLY)) < 0){
			printf("Error in open FIFO\n");
			exit(1);
	}
	while(1){
		scanf("%s", filename);
		if(write(fd, filename, sizeof(filename)) != sizeof(filename)){
			printf("Error write\n");
			exit(1);
		}
		if(strstr(filename,FILENAME) != NULL){
			for(short int i = 0; i<strlen(filename)-FNBEGIN;i++){
				newname[i] = filename[i+FNBEGIN];
			}
			printf("filename: %s\n",newname);
			break;
		}
	}
	printf("Введите название пункта: \n");
	scanf("%s", Search);
	if(write(fd, Search, sizeof(Search)) != sizeof(Search)){
			printf("Error write\n");
			exit(1);
	}
	close(fd);
	sleep(5);
    if((fd = open(FIFO, O_RDONLY)) < 0){
		printf("Error in open FIFO\n");
		exit(1);
	}
	while ((n = read(fd, buff, MAXBUFF)) > 0){
		DataPrint(buff);
    }
	exit(0);
}
