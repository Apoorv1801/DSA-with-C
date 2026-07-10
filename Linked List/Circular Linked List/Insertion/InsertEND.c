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
int choice = 1;
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
newnode = (struct node *)malloc(sizeof(struct node));
printf("\nEnter number for insertion:");
scanf("%d",&newnode -> num);
newnode -> next = tail -> next;
tail -> next = newnode;
tail = newnode;
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

