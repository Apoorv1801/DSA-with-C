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
int choice = 1,i = 1;
int pos,count = 0;
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
count ++;
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
printf("\nEnter position of deletion:");
scanf("%d",&pos);
if(pos>count)
{
printf("\nInvalid Position");
}
else
{
temp = head;
while(i<pos)
{
temp = temp -> next;
i++;
}
temp -> prev -> next = temp -> next;
temp -> next -> prev = temp -> prev;
free(temp);
}
printf("\nLinked List After Deletion:-\n");
temp = head;
while(temp!=0)
{
printf("%d ",temp -> num);
temp = temp -> next;
}
return 0;
}

