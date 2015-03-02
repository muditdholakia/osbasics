#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
main(int argc,char *argv[])
{
	int x=0,y=0,i=0,m,k=0,s,pos=0,l,h;
	char a[500000],fname[100];	
		
		
		if(*argv[1]=='x')
		{
			x=open(argv[2],O_WRONLY | O_APPEND);
			if(x<0)
			{
				h=creat(argv[2],O_RDWR | O_APPEND | O_RDONLY | O_WRONLY);
				x=open(argv[2],O_WRONLY | O_APPEND);
			}

			if(argc>3)
			{			
				for(i=3;i<=argc;i++)
				{
					l=open(argv[i],O_RDONLY);
					y=read(l,a,sizeof(a));
					s=write(x,a,y);
					close(l);
				}
				close(x);		
			}
			else
			{
				for(;;)
				{				
					y=read(0,a,sizeof(a));
					s=write(x,a,y);
					close(x);
				}
			}		
}
