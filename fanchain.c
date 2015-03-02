#include<stdio.h>
#include<sys/types.h>
void main(void)
{
	pid_t pid;
	int n,i,ch;
	printf("FOR FANNING PRESS 1:FOR CHAINING PRESS 2:--");
	scanf("%d",&ch);
	if(ch==1)
	{
		printf("ENTER NUMBER OF CHILDREN YOU WANT TO CREATE::--");
		scanf("%d",&n);	
		for(i=0;i<n;i++)
		{
			pid = fork();
			if(pid!=0)
			{
				printf("ID of child: %d:is:%d\n",i,pid);
				continue;
			}
			else
			{
				return;
			}
		}
	}
	else if(ch==2)
	{
		printf("ENTER NUMBER OF LEVELS YOU WANT TO CREATE::--");
		scanf("%d",&n);
		printf("ID of Parent is:%d\n",getpid());	
		for(i=0;i<n;i++)
		{
			pid = fork();
			if(pid!=0)
			{
				return;			
			}
			else
			{
				printf("Parent of: %d:is:%d\n",i,pid);			
				continue;
			}
		}
	}
return;
}
