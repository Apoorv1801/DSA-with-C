#include<stdio.h>
int main()
{
int a[50],size,temp,i,j;
printf("\nEnter the size of array:");
scanf("%d",&size);
printf("\nEnter the elements of array:");
for(i=0;i<size;i++)
{
scanf("%d",&a[i]);
}
printf("\nArray before sorting:- \n");
for(i=0;i<size;i++)
{
printf("%d ",a[i]);
}
for(i=0;i<size;i++)
{
for(j=i+1;j<size;j++)
{
if(a[i]>a[j])
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}
printf("\nArray after sorting:- \n");
for(i=0;i<size;i++)
{
printf("%d ",a[i]);
}
}


