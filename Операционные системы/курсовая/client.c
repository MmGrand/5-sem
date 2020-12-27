#include "./mesg.h"
 
main()
{
   Message message;
   key_t key;
   int msgid, length, k;
   message.mtype = 1L;
   char mass[80];
if ( (key = ftok("server", 'A')) < 0)
   {
    printf("Невозможно получить ключ\n"); 
	exit(1);
   }
 
   if ((msgid = msgget(key, 0)) < 0)
   {
    printf("Невозможно получить доступ к очереди\n"); 
	exit(1);
   }
 
while(1)
{
   printf("Введите строку: ");
   scanf("%s", mass); 
   	if (strcmp(mass, "bye") == 0)
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
	else
	{
		if ((length = sprintf(message.buff, mass)) < 0)
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
   k=msgrcv(msgid, &message, sizeof(message), message.mtype, 0);
   if (k > 0) 
   {
    if (write(1, message.buff, k) != k)
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
	if(strcmp(mass, "bye") == 0)
		{
			break;		
		}
}
if (msgctl(msgid, IPC_RMID, 0) < 0)
  {
    printf("Ошибка удаления очереди\n"); 
	exit(1);
  } 
exit(0);
}
