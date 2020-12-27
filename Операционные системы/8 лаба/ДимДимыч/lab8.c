#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	
	FILE *a, *b;
	char ch;
	pid_t pid;
	int channel[2];
	printf("file = %s\n",argv[1]);
	
	if(pipe(channel) < 0){
		printf("Pipe failed\n");
		exit(-1); 
	}
	
	pid = fork();
	
	if(pid == -1){
		perror("fork"); 
		exit(1);
	}
	else if(pid == 0){
		close(channel[1]);
		b = fopen("upgrade.txt","w");
		while(!feof(b) && ch!=EOF){
			read(channel[0], &ch, sizeof(char));
			if(ch!=EOF){
				if(ch == 'b') ch='N';
				if(ch == 'i') ch='A';
				if(ch == 'n') ch='D';
				putc(ch, b);
			}
		}
		close(channel[0]);
		fclose(b);
		sleep(1);
	}
	else{
		close(channel[0]);
		a = fopen(argv[1],"r");
		while(!feof(a) && ch!=EOF) {
			ch=fgetc(a);
			write(channel[1], &ch, sizeof(char));
		}
		close(channel[1]);
		fclose(a);
		sleep(1);
	}
	return (0);
}
