#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
main(int argc,char *argv[])
{
	int x=0,y=0,i=0,l,k=0,m,pos=0;
	char a[2048],fname[100];
	
	if(argc==1)
	{
		for(;;)
		{
			x=read(0,a,sizeof(a));
			write(1,a,x);
		}
	}
	for(i=0;i<argc;i++)
	{
		if(argv[i]=='>')
		{
			pos=i;
			break;			
		}		
				
	}
	if(pos=0)
	{
		for(i=1;i<argc;i++)
		{
			x=open(argv[i],O_RDONLY);
			y=read(x,a,sizeof(a));
			write(1,a,y);
		}
	}
	else
	{
		if(pos==1)
		{
			x=open(argv[2],O_WRONLY);
			if(x==-1)
			{
				s=creat(argv[2],O_RDWR);
			}
				x=open(argv[2],O_RDONLY);
				y=read(0,a,sizeof(a));
				write(x,a,y);	
		}
	}
	
		
}
