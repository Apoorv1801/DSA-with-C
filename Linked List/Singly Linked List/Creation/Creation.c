#include <stdio.h>
int main()
{
struct node
{
int num;
struct node *next;
};
struct node *head,*newnode,*temp;
head = 0;
int choice = 1;
while(choice)
{
newnode = (struct node *)malloc(sizeof(struct node));
printf("\nEnter a number:");
scanf("%d",&newnode -> num);
newnode -> next = 0;
if(head==0)
{
head = temp = newnode;
}
else
{
temp -> next = newnode;
temp = newnode;
}
printf("\nPress (1) to add elements OR (0) to end:");
scanf("%d",&choice);
}
printf("\nLinked List :- \n");
temp = head;
while(temp!=0)
{
printf("%d ",temp -> num);
temp = temp -> next;
}
return 0;
}
