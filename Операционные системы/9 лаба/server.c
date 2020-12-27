#include "./lab9.h"
char *newfile = "RESULT.dat";

void Processfile(char *filename, char *newfile){
	FILE *f,*f2;
	int k,l=0;
	f=fopen(filename,"rb");
	f2=fopen(newfile,"wb");
	fread(&t, sizeof(t), 1, f);
	while (!feof(f)){
        k=0;
		for(int i=0;i<3;i++)
			if(t.A[i]==2)
					k++;
		if(k>=1)
			{
			fwrite(&t, sizeof(t), 1, f2);
			l++;
			}
		fread(&t, sizeof(t), 1, f);					
					}
	fclose(f);
	fclose(f2);
}

int main (void){
	int n;
	char *f = (char *)calloc(MAXBUFF , sizeof(char));
	char *buff = (char *)calloc(MAXBUFF , sizeof(char)); 
	
	if (mknod(FIFO, S_IFIFO | 0666, 0) < 0){
		printf("Невозможно создать FIFO\n");
		exit(1);
	}
	
	if ((fd = open(FIFO, O_RDONLY)) < 0){
		printf("Невозможно открыть FIFO\n");
		exit(1);
	}
	
	while ((n = read(fd, buff, MAXBUFF)) > 0){
		printf("Current Buffer: %s\n",buff);
		if(strstr(buff,FILENAME) != NULL){
			for(short int i = 0; i<strlen(buff)-FNBEGIN;i++){
				f[i] = buff[i+FNBEGIN];
			}
			printf("filename: %s\n",f);
			break;
		}
	}
	Processfile(f, newfile);
	free(buff);
	close(fd);
	if ((fd = open(FIFO, O_WRONLY)) < 0){
		printf("Невозможно открыть FIFO\n");
		exit(1);
	}
	if(write(fd, newfile, strlen(newfile)) != strlen(newfile)){
			printf("Error write\n");
			exit(1);
		}
	close(fd);
	
	if (unlink(FIFO) < 0){
		printf("Невозможно удалить FIFO\n"); 
		exit(1);
	}
	exit(0);
}
