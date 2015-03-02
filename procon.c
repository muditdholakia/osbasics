#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int max=1000,a,b,cstk[1000],i;
void *producer();
void *consumer();
main()
{
pthread_t thread1[1000], thread2[1000];

int iret1[1000], iret2[1000];
a=0;
b=0;
for(i=0;i<1000;i++)
{
iret1[i]=pthread_create(&thread1[i],NULL,producer,NULL);
iret2[i]=pthread_create(&thread2[i],NULL,consumer,NULL);
pthread_join( thread1[i], NULL);
pthread_join( thread2[i], NULL);
}
}
void *producer()
{
if(a==1000)
{
	if(cstk[0]==0)
	{
		a=0;
		cstk[a]=1;
		printf("\nItem no produced at:-%d\n",a);
		a=a+1;
	}
	else
	{
		printf("STACK IS FULL!!\n");
	}
}
else if(cstk[a]==1)
{
	printf("\nSTACK IS FULL!!\n");
}
else
{
	cstk[a]=1;
	printf("\nItem no produced at:-%d\n",a);
	a=a+1;
}
}
void *consumer()
{
if(b==1000)
	{
	if(cstk[0]==1)
	{
		b=0;
		cstk[b]=0;
		printf("\nItem no consumed at:-%d\n",b);
		b=b+1;
	}
	else
	{
		printf("\nSTACK IS EMPTY!!\n");
	}
}
else if(cstk[b]==0)
{
	printf("\nSTACK IS EMPTY!!\n");
}
else
{
	cstk[b]=0;
	printf("\nItem no consumed at:-%d\n",b);
	b=b+1;
}
}
