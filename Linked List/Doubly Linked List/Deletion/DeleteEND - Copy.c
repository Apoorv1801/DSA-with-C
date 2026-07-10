#include <stdio.h>
int main()
{
struct node
{
int num;
struct node *next;
struct node *prev;
};
struct node *head,*newnode,*tail,*temp;
head = 0;
int choice = 1;
while(choice)
{
newnode = (struct node *)malloc(sizeof(struct node));
printf("\nEnter a number:");
scanf("%d",&newnode -> num);
newnode -> next = 0;
newnode -> prev = 0;
if(head==0)
{
tail = head = newnode;
}
else
{
tail -> next = newnode;
newnode -> prev = tail;
tail = newnode;
}
printf("\nEnter (1) to add elements OR (0) to end:");
scanf("%d",&choice);
}
printf("\nLinked List Before Deletion:-\n");
temp = head;
while(temp!=0)
{
printf("%d ",temp -> num);
temp = temp -> next;
}
tail -> prev -> next = 0;
free(tail);
printf("\nLinked List After Deletion:-\n");
temp = head;
while(temp!=0)
{
printf("%d ",temp -> num);
temp = temp -> next;
}
return 0;
}
