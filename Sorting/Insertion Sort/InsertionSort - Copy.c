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
for(i=1;i<size;i++)
{
temp=a[i];
j=i-1;
while(j>=0 && a[j]>temp)
{
a[j+1]=a[j];
j--;
}
a[j+1]=temp;
}
printf("\nArray after sorting:- \n");
for(i=0;i<size;i++)
{
printf("%d ",a[i]);
}
return 0;
}







