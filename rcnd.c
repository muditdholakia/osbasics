#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#define SIZE 1000
#define SIZE_1 20
long count=0,in=0,out=0;
long buffer[SIZE];
int retVal=0;
FILE *fp;
void producer()
{
	fp = fopen("Output.txt", "a+");	
	fprintf(fp,"%s %u\n","In Producer ",pthread_self());
	while(retVal==0)
	{
		if(count<SIZE)
		{
			buffer[in]=in;
			fprintf(fp,"%s %s %u %ld\n","Producer  :", "Item produced",pthread_self(),in);
			count++;
			in = (in+1)%SIZE;
		}
	}
	fprintf(fp,"%s %u","At end of Producer ",pthread_self());	
}
void consumer()
{
	fp = fopen("Output.txt", "a+");
	fprintf(fp, "%s %u\n","In Consumer",pthread_self());
	while(retVal==0)
	{
		while(count==0);
			
		if((buffer[out]!=out) && buffer[out]>-1)
		{
			retVal=-1;
			fprintf(fp,"%s %ld %u\n","Race condition has occured at place",out,pthread_self());
			return;			
		}
		else
		{
			fprintf(fp,"%u %ld %ld %ld\n","Consumer: Item  consumed at index",pthread_self(),buffer[out],out);
			count--;
			out=(out+1)%SIZE;
		}
	}
	fprintf(fp,"%s %u\n","At end of Consumer",pthread_self());	
}
int main()
{
	pthread_t pTid[SIZE_1];
	pthread_t cTid[SIZE_1];
	int i=0;
	long index=0;
	
	for(index=0;index<SIZE;index++)
		buffer[index]=-1;
		
	for(index=0;index<SIZE_1;index++)
	{	
		if(pthread_create(&pTid[index],NULL,(void *)producer,NULL)!=0)
		{
			printf("Error in creation of producer thread\n");
			return -1;
		}
		else
			printf("Producer thread is cretated\n");
	}

	for(index=0;index<SIZE_1;index++)
	{
		if(pthread_create(&cTid[index],NULL,(void *)consumer,NULL)!=0)
		{
			printf("Error in creation of consumer thread\n");
			return -1;
		}
		else
			printf("Consumer thread is cretated\n");
	}

	for(i=0;i<SIZE_1;i++)
	{
		if(pthread_join(pTid[i],NULL)!=0)
		{
			printf("Error in join of thread %d\n",pTid[i]);
			return -1;
		}
	}

	for(i=0;i<SIZE_1;i++)
	{
		if(pthread_join(cTid[i],NULL)!=0)
		{
			printf("Error in join of thread %d\n",cTid[i]);
			return -1;
		}
	}
	
	return 0;
}

