#include<stdio.h>
int main()
{
int a[50],size,min,temp,i,j;
printf("\nEnter the size of array:");
scanf("%d",&size);
printf("\nEnter elements of the array:");
for(i=0;i<size;i++)
{
scanf("%d",&a[i]);
}
printf("\nArray before sorting :- \n");
for(i=0;i<size;i++)
{
printf("%d ",a[i]);
}
for(i=0;i<size-1;i++)
{
int min = i;
for(j=i+1;j<size;j++)
{
if(a[j]<a[min])
{
min = j;
}
if(min!=i)
{
temp=a[i];
a[i]=a[min];
a[min]=temp;
}
}
}
printf("\nArray after sorting :- \n");
for(i=0;i<size;i++)
{
printf("%d ",a[i]);
}
return 0;
}
