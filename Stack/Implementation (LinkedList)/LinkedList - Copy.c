 #include <stdio.h>
 #include <stdlib.h>

 struct node
 {
     int num;
     struct node *next;
 };

 struct node *top = 0;

 void push()
 {
     struct node *newnode;
     newnode = (struct node *)malloc(sizeof(struct node));
     printf("\nEnter a number:");
     scanf("%d",&newnode -> num);
     newnode -> next = top;
     top = newnode;
 }

 void display()
 {
     struct node *temp;
     temp = top;
     if(top == 0)
     {
         printf("\nUnderflow");
     }
     else
     {
         printf("\nStack:-\n");
         while(temp!= 0)
         {
             printf("%d ",temp -> num);
             temp = temp -> next;
         }
     }
 }

 void peak()
 {
     if(top == 0)
     {
         printf("\nUnderflow");
     }
     else
     {
         printf("\nTop Element of the stack = %d",top -> num);
     }
 }

 void pop()
 {
     struct node *del;
     del = top;
     if(top == 0)
     {
         printf("\nUnderflow");
     }
     else
     {
         printf("\nPopped number = %d",top->num);
         top = top -> next;
         free(del);
     }
 }

 int main()
 {
     int ch;
     do
     {
         printf("\nEnter choice 0-Exit 1-Push 2-Pop 3-Peak 4-Display :-\n");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1:
                 push();
                 break;
             case 2:
                 pop();
                 break;
             case 3:
                 peak();
                 break;
             case 4:
                 display();
                 break;
             default:
                printf("\nInvalid Choice");
         }
     }while(ch!=0);
 return 0;
 }

