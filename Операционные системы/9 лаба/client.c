#include "./lab9.h"

void Printnewfile(char *filename){
	int j=0;
	FILE *f;
	printf("Результат обработки:\n");
	f=fopen(filename,"rb");
	fread(&t, sizeof(t), 1, f);
	while (!feof(f)){
		printf("\nГруппа:%3d \nФамилия и инициалы:%s\n",t.group, t.name);
		for(int i=0;i<3;i++)
			printf("%d\t",t.A[i]); 
		j++;
		printf("\n");  
		fread(&t, sizeof(t), 1, f);
	}
	fclose(f);
	if (j==0) printf("Таких студентов нет\n");
}

int main(int argc, char *argv[]){
	char f[MAXBUFF], newname[MAXBUFF];
	int n;
    char *buff = (char *)calloc(MAXBUFF, sizeof(char)); 
	if((fd = open(FIFO, O_WRONLY)) < 0){
			printf("Error in open FIFO\n");
			exit(1);
	}
	while(1){
		scanf("%s", f);
		if(write(fd, f, sizeof(f)) != sizeof(f)){
			printf("Error write\n");
			exit(1);
		}
		if(strstr(f,FILENAME) != NULL){
			for(short int i = 0; i<strlen(f)-FNBEGIN;i++){
				newname[i] = f[i+FNBEGIN];
			}
			printf("filename: %s\n",newname);
			break;
		}
	}
	close(fd);
	sleep(5);
    if((fd = open(FIFO, O_RDONLY)) < 0){
		printf("Error in open FIFO\n");
		exit(1);
	}
	while ((n = read(fd, buff, MAXBUFF)) > 0){
		Printnewfile(buff);
    }
	exit(0);
}
