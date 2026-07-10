#include<stdio.h>
#include<stdlib.h>
int main()
{
struct node
{
int num;
struct node *next;
};
struct node *tail,*newnode,*temp;
tail = 0;
int choice = 1,i = 1;
int count = 0,pos;
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
printf("\nLinked List Before Insertion:-\n");
temp = tail -> next;
while(temp -> next != tail -> next)
{
printf("%d ",temp -> num);
temp = temp -> next;
}
printf("%d",temp -> num);
printf("\nEnter position of insertion:");
scanf("%d",&pos);
if(pos>count)
{
printf("\nInvalid Position");
}
else
{
newnode = (struct node *)malloc(sizeof(struct node));
printf("\nEnter number for insertion:");
scanf("%d",&newnode -> num);
temp = tail -> next;
while(i<pos-1)
{
temp = temp -> next;
i++;
}
newnode -> next = temp -> next;
temp -> next = newnode;
}
printf("\nLinked List After Insertion:-\n");
temp = tail -> next;
while(temp -> next != tail -> next)
{
printf("%d ",temp -> num);
temp = temp -> next;
}
printf("%d",temp -> num);
return 0;
}


