#include "./lab9.h"
char *newfile = "RESULT.dat";

void DataProcessing(char *filename, char *Search, char *newfile){
	FILE *f, *f2;
	f=fopen(filename,"rb");
	fread(&t, sizeof(t), 1, f);
  	f2=fopen(newfile,"wb");
	while (!feof(f)){
        if(strcmp(Search,t.nPunkt)==0 || strcmp(Search,t.kPunkt)==0)
	 {
		fwrite(&t, sizeof(t), 1, f2);	
	 }
	 fread(&t, sizeof(t), 1, f);
	}
	fclose(f);
	fclose(f2);
}

int main (void){
	int n,num;
	char *filename = (char *)calloc(MAXBUFF , sizeof(char));
	char *buff = (char *)calloc(MAXBUFF , sizeof(char)); 
	char Search[15]; 
	
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
				filename[i] = buff[i+FNBEGIN];
			}
			printf("filename: %s\n",filename);
			break;
		}
	}
	if((n = read(fd, Search, MAXBUFF)) > 0){
		printf("Название введённого пункта == %s\n",Search);
		DataProcessing(filename, Search, newfile);
	}
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
