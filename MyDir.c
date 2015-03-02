#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
void traverse(char *fn, int indent);
int main(int argc, char * argv[]) 
{
	  puts("Directory structure:");
	  traverse(argv[1], 0);
	  return 0;
}
void traverse(char *fn, int indent) 
{
	  DIR *dir;
	  struct dirent *entry;
	  int count;
	  char path[1025];
	  struct stat info;
	  for (count=0; count<indent; count++) 
	  	printf("  ");
	  if ((dir = opendir(fn)) == NULL)
		perror("opendir() error");
	  else 
	  {
    		while ((entry = readdir(dir)) != NULL) 
    		{
		      if (entry->d_name[0] != '.') 
		      {
		        strcpy(path, fn);
		        strcat(path, "/");
		        strcat(path, entry->d_name);
		        if (stat(path, &info) == 0)
		        	printf("%s\n",path);
		     		if (S_ISDIR(info.st_mode))
               				traverse(path, indent+1);
      		      }
    		}
	    closedir(dir);
  	}
}


