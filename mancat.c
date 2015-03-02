#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
main(int argc,char *argv[])
{		
		x=open(argv[2],O_WRONLY | O_APPEND);
		y=read(0,a,sizeof(a));
		s=write(x,a,y);
		close(x);
}
