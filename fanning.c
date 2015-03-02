#include<stdio.h>
#include<sys/types.h>
void main(void)
{
	pid_t pid;
	int n,i;
	printf("ENTER NUMBER OF CHILDREN YOU WANT TO CREATE::--");
	scanf("%d",&n);	
	for(i=0;i<n;i++)
	{
		pid = fork();
		if(pid!=0)
		{
			printf("ID of child: %d:is:%d\n",i,pid);
			return;
		}
	}
return;
}
