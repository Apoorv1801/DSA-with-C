#include<stdio.h>
#include<stdlib.h>
int main()
{
struct node
{
int num;
struct node *next;
};
struct node *tail,*newnode,*nextn,*temp;
tail = 0;
int choice = 1,count = 0, i = 1;
int pos;
while(choice)
{
newnode = (struct node *)malloc(sizeof(struct node));
printf("\nEnter a number:");
scanf("%d",&newnode -> num);
newnode -> next = 0;
if(tail==0)
{
tail = newnode;
tail -> next = newnode;
}
else
{
newnode -> next = tail -> next;
tail -> next = newnode;
tail = newnode;
count++;
}
printf("\nEnter (1) to add elements & (0) to end:");
scanf("%d",&choice);
}
printf("\nLinked List Before Deletion:-\n");
temp = tail -> next;
while(temp -> next != tail -> next)
{
printf("%d ",temp -> num);
temp = temp -> next;
}
printf("%d",temp -> num);
printf("\nEnter position of deletion:");
scanf("%d",&pos);
if(pos - 1 > count)
{
printf("Invalid Position");
}
else
{
temp = tail -> next;
while(i<pos-1)
{
temp = temp -> next;
i++;
}
nextn = temp -> next;
temp -> next = nextn -> next;
if(nextn -> next == tail -> next)
{
temp -> next  = tail -> next;
tail = temp;
}
free(nextn);
printf("\nLinked List After Deletion:-\n");
temp = tail -> next;
while(temp -> next != tail -> next)
{
printf("%d ",temp -> num);
temp = temp -> next;
}
printf("%d",temp -> num);
}
return 0;
}

