#include <stdio.h>
int main()
{
struct node
{
int num;
struct node *next;
};
struct node *head,*newnode,*temp,*nextnode;
head = 0;
int choice = 1,i = 1,pos;
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
printf("\nLinked List Before Deletion:- \n");
temp = head;
while(temp!=0)
{
printf("%d ",temp -> num);
temp = temp -> next;
}
printf("\nEnter position of deletion:");
scanf("%d",&pos);
temp = head;
while(i<pos-1)
{
temp = temp -> next;
i++;
}
nextnode = temp -> next;
temp -> next = nextnode -> next;
free(nextnode);
printf("\nLinked List After Deletion:-\n");
temp = head;
while(temp!=0)
{
printf("%d ",temp -> num);
temp = temp -> next;
}
return 0;
}

