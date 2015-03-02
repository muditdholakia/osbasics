#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>

int main () 
{
    int len;
    struct dirent *pDirent;
    DIR *pDir;
    pDir =  opendir ("/proc");
    char temp[100],path[100],buff[100];
    int fp;
    if (pDir == NULL) {
        printf ("Cannot open directory \n" );
        return 1;
    }
    while ((pDirent = readdir(pDir)) != NULL) {
        printf ("%s\t", pDirent->d_name);
	strcpy(path, "/proc/");
	strcpy(temp,pDirent->d_name);
	strcat(path,temp);
	strcat(path,"/cmdline");
//	printf("%s\n",path);
	fp = open(path,O_RDONLY);
	read(fp,buff,sizeof(buff));
	printf("%s\n",buff);
	bzero(buff,sizeof(buff));
//	write(1,buff,sizeof(buff));
		   }

   /*while (1)
   {
        printf ("[%c]\n", pDirent->d_type);
    }*/
    closedir (pDir);
    return 0;

}
