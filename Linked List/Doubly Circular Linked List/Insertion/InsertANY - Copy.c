#include <stdio.h>
#include <stdlib.h>
int main()
{
struct node
{
int num;
struct node *next;
struct node *prev;
};
struct node *head,*tail,*newnode,*temp;
head = 0;
int choice = 1;
int count = 0;
int pos, i = 1;
while(choice)
{
newnode = (struct node *)malloc(sizeof(struct node));
printf("\nEnter a number:");
scanf("%d",&newnode -> num);
if(head==0)
{
head = tail = newnode;
head -> next = head;
head -> prev = head;
}
else
{
tail -> next = newnode;
newnode -> prev = tail;
newnode -> next = head;
head -> prev = newnode;
tail = newnode;
count++;
}
printf("\nEnter (1) to add elements and (0) to end:");
scanf("%d",&choice);
}
printf("\nLinked List Before Insertion:-\n");
temp = head;
while(temp != tail)
{
printf("%d ",temp -> num);
temp = temp -> next;
}
printf("%d",temp -> num);
newnode = (struct node *)malloc(sizeof(struct node));
printf("\nEnter number for insertion:");
scanf("%d",&newnode -> num);
printf("\nEnter position of insertion:");
scanf("%d",&pos);
if(pos>count)
{
printf("Invalid Position");
}
else
{
temp = head;
while(i<pos-1)
{
temp = temp -> next;
i++;
}
}
newnode -> prev = temp;
newnode -> next = temp -> next;
temp -> next -> prev = newnode;
temp -> next = newnode;
printf("\nLinked List After Insertion:-\n");
temp = head;
while(temp != tail)
{
printf("%d ",temp -> num);
temp = temp -> next;
}
printf("%d",temp -> num);
return 0;
}














