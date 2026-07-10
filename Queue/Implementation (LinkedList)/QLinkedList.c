 #include <stdio.h>
 #define N 5

 struct node
 {
    int num;
    struct node *next;
 };
 struct node *front = 0;
 struct node *rear = 0;

  void enqueue()
 {
     int x;
     printf("\nEnter a number:");
     scanf("%d",&x);
     struct node *newnode;
     newnode = (struct node *)malloc(sizeof(struct node));
     newnode -> num = x;
     newnode -> next = 0;
     if(front == 0 && rear == 0)
     {
         front = rear = newnode;
     }
     else
     {
         rear -> next = newnode;
         rear = newnode;
     }
 }

 void dequeue()
 {
     struct node *temp;
     temp = front;
     if(front == 0 && rear == 0)
     {
         printf("\nUnderflow");
     }
     else
     {
         printf("\nDequeued Element = %d",front -> num);
         front = front -> next;
         free(temp);
     }
 }

 void peak()
 {
     if(front == 0 && rear == 0)
     {
         printf("\nUnderflow");
     }
     else
     {
         printf("\nPeak Element = %d",front -> num);
     }
 }

 void display()
 {
     struct node *temp;
     if(front == 0 && rear == 0)
     {
         printf("\nUnderflow");
     }
     else
     {
         temp = front;
         printf("\nQueue:-\n");
         while(temp != 0)
         {
             printf(" %d |",temp -> num);
             temp = temp -> next;
         }
     }
 }

 int main()
 {
     int ch;
     do
     {
         printf("\nEnter choice 0-Exit 1-Enqueue 2-Dequeue 3-Peak 4-Display :-\n");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1:
                 enqueue();
                 break;
             case 2:
                 dequeue();
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
