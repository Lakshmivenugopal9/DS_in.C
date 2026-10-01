#include<stdio.h>
#include<stdlib.h>
int main()
{
int i,n;
int *ptr;
printf("Enter the size:");
scanf("%d",&n);
ptr=(int *)calloc(n,sizeof(int));
printf("Enter the value %d",n);
for(i=0;i<n;i++)
{
scanf("%d",&ptr[i]);
}
printf("The values entered are: %d",n);
for(i=0;i<n;i++)
{
printf("%d\n",&ptr[i]);
}
free(ptr);
return 0;
}