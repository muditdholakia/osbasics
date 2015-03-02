#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int m1[100][100],m2[100][100],m3[100][100],iret[100],i,n1,n2,n3,n4,temp,j,k,l,p,q;
void *matrix_multiplication_function();
main()
{
pthread_t thread1[100];

printf("Enter 1st dimention of 1st matrix:-");
scanf("%d",&n1);
printf("Enter 2nd dimention of 1st matrix:-");
scanf("%d",&n2);
printf("Enter 1st dimention of 2nd matrix:-");
scanf("%d",&n3);
printf("Enter 2nd dimention of 2nd matrix:-");
scanf("%d",&n4);
printf("Details of first matrix:-\n-----------------------------------\n");
for(p=0;p<n1;p++)
{
	for(q=0;q<n2;q++)
	{
		printf("Enter element number%d%d",p,q);
		scanf("%d",&m1[p][q]);
	}
}
printf("Details of second matrix:-\n----------------------------------\n");
for(p=0;p<n3;p++)
{
	for(q=0;q<n4;q++)
	{
		printf("Enter element number%d%d",p,q);
		scanf("%d",&m2[p][q]);
	}
}
for(i=0;i<(n1*n4);i++)
{
	iret[i] = pthread_create(&thread1[i], NULL, matrix_multiplication_function,NULL);
}
for(i=0;i<(n1*n4);i++)
{
	pthread_join( thread1[i], NULL);
}
printf("RESULTANT MATRIX:-\n-------------------------------------\n");
for(p=0;p<n1;p++)
{
	for(q=0;q<n4;q++)
	{
		printf("%d\t",m3[p][q]);
	}
	printf("\n");
}
}
void *matrix_multiplication_function()
{
for(j=0;j<n1;j++)
{
		for(k=0;k<n4;k++)
		{
			temp=0;			
			for(l=0;l<n3;l++)
			{			
			temp=temp+(m1[j][l]*m2[l][k]);
			}
			m3[j][k]=temp;
		}
}
}
