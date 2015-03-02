#include <sys/types.h>
 #include <dirent.h>
 #define _SVID_SOURCE
 #include<stdio.h>
       /* print files in current directory in reverse order */

       int main(void)
       {
           struct dirent **namelist;
           int n;

           n = scandir(".", &namelist, 0, alphasort);
           if (n < 0)
               perror("scandir");
           else {
               while (n--) {
                   printf("%s%u\n", namelist[n]->d_name,namelist[n]->d_type);
                   
               }
             }
       }

