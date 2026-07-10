 #include <stdio.h>
 #define N 5
 int stack[N];
 int top = -1;
 void push()
 {
     int x;
     printf("\nEnter a number:");
     scanf("%d",&x);
     if(top == N - 1)
     {
         printf("\nOverflow");
     }
     else
     {
         top++;
         stack[top] = x;
     }
 }
 void pop()
 {
     int item;
     if(top == -1)
     {
         printf("\nUnderflow");
     }
     else
     {
         item = stack[top];
         top--;
         printf("\nPopped Number = %d",item);
     }
 }
 void peak()
 {
     if(top == -1)
     {
         printf("\nUnderflow");
     }
     else
     {
         printf("\nStack Top = %d",stack[top]);
     }
 }
 void display()
 {
     int i;
     printf("\nStack :-\n");
     for(i=top;i>=0;i--)
     {
         printf("%d ",stack[i]);
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
