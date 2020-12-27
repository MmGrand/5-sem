#include "./mesg.h"
	
void zamena(char *str)
{		
	int l;
	l=strlen(str);
	for(int i=0;i<l;i++)
		if(str[i]=='a') str[i]='O';
}
 
main ()
{
   Message message;
   key_t key;
   int msgid, length, n;
   char mass[80], c;
 
   if ((key = ftok("server", 'A')) < 0)
   {
    printf("Невозможно получить ключ\n");
	exit(1);
   } 
 
   message.mtype=1L;
 
   if ((msgid = msgget(key, PERM | IPC_CREAT)) < 0)
   {
    printf("Невозможно создать очередь\n"); 
	exit(1);
   }
 
   while(1)
   {
      n=msgrcv(msgid, &message, sizeof(message), message.mtype, 0);
      if (n > 0) 
      {
     	if (write(1, message.buff, n) != n)
         	{
             	printf("Ошибка вывода\n"); 
				exit(1);
         	}
      	} 
      	else 
      	{ 
      	printf("Ошибка чтения сообщения\n"); 
		exit(1);
      	}
   
      	printf("\n");
 
      	if (strcmp(message.buff, "bye") == 0)
     	 {   
         	if ((length = sprintf(message.buff, "bye")) < 0)
        	 {
        	printf("Ошибка копирования в буфер\n"); 
			exit(1);
        	 } 
 
         	if (msgsnd(msgid, (void *) &message, length, 0) !=0)
         	{
        	printf("Ошибка записи сообщения в очередь\n");
			exit(1);
         	}  
      	}
		else if (strcmp(message.buff, "hello") == 0)
     	 {   
         	if ((length = sprintf(message.buff, "hi")) < 0)
        	 {
        	printf("Ошибка копирования в буфер\n"); 
			exit(1);
        	 } 
 
         	if (msgsnd(msgid, (void *) &message, length, 0) !=0)
         	{
        	printf("Ошибка записи сообщения в очередь\n");
			exit(1);
         	}  
      	}
		else
		{
		zamena(message.buff);
			if ((length = sprintf(mass, message.buff)) < 0)
        	 {
        	printf("Ошибка копирования в буфер\n"); 
			exit(1);
        	 } 
 
         	if (msgsnd(msgid, (void *) &message, length, 0) !=0)
         	{
        	printf("Ошибка записи сообщения в очередь\n");
			exit(1);
         	}  
		}
	if(strcmp(message.buff, "bye") == 0)
		{
			exit(0);		
		}
	memset(message.buff,0,80);   
	}
}
