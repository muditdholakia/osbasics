#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <sys/wait.h>  
#include <unistd.h>   
#include <string.h>
   
#define SIZE 24

int main() 
{
   int shmid;
   char *shm;

   if(fork() == 0) 
   {
	shmid = shmget(2009, SIZE, 0666 | IPC_CREAT);
        shm = shmat(shmid, 0, 0);
        char *s = (char *) shm;
        *s = '\0';  
        int i;
        
        for(i=0; i<5; i++) 
        {
        	int n;  
                printf("Enter number<%i>: ", i);
                scanf("%d", &n);
                sprintf(s, "%s%d", s, n);  
        }
     
        strcat(s, "\n"); 
        printf ("Child wrote <%s>\n",shm);
        shmdt(shm);
   }
   
   else 
   {
     
      shmid = shmget(2009, SIZE, 0666 | IPC_CREAT);
      shm = shmat(shmid, 0, 0);
      wait(NULL);
      printf ("Parent reads <%s>\n",shm) ;
      shmdt(shm);
      shmctl(shmid, IPC_RMID, NULL);
   }
   
   return 0;
}





/*
[user1@centosOS6 SharedMemory]$ gcc shared.c -o shared
[user1@centosOS6 SharedMemory]$ ./shared
Enter number<0>: 1
Enter number<1>: 2
Enter number<2>: 3
Enter number<3>: 4
Enter number<4>: 5
Child wrote <12345
>
Parent reads <12345
>

*/
