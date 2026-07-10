#include <stdio.h>
int main()
{
struct node
{
int num;
struct node *next;
struct node *prev;
};
struct node *head,*newnode,*tail,*current,*nextnode,*temp;
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
head = tail = newnode;
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
printf("\nLinked List Before Reversing:-\n");
temp = head;
while(temp!=0)
{
printf("%d ",temp -> num);
temp = temp -> next;
}
current = head;
while(current!=0)
{
nextnode = current -> next;
current -> next = current -> prev;
current -> prev = nextnode;
current = nextnode;
}
current = head;
head = tail;
tail = current;
printf("\nLinked List After Reversing:-\n");
temp = head;
while(temp!=0)
{
printf("%d ",temp -> num);
temp = temp -> next;
}
return 0;
}


