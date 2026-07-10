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
int count = 0, i = 1;
int choice = 1,pos;
while(choice)
{
newnode = (struct node *)malloc(sizeof(struct node));
printf("\nEnter a number:");
scanf("%d",&newnode -> num);
newnode -> next = 0;
newnode -> prev = 0;
if(head==0)
{
head = tail = newnode;
}
else
{
tail -> next = newnode;
newnode -> prev = tail;
tail = newnode;
count++;
}
printf("\nEnter (1) to add elements OR (0) to end:");
scanf("%d",&choice);
}
printf("\nLinked List Before Insertion:-\n");
temp = head;
while(temp!=0)
{
printf("%d ",temp -> num);
temp = temp -> next;
}
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
newnode -> next = 0;
newnode -> prev = 0;
temp = head;
while(i<pos-1)
{
temp = temp -> next;
i++;
}
newnode -> prev = temp;
newnode -> next = temp -> next;
temp -> next = newnode;
newnode -> next -> prev = newnode;
}
printf("\nLinked List After Insertion:-\n");
temp = head;
while(temp!=0)
{
printf("%d ",temp -> num);
temp = temp -> next;
}
return 0;
}


