 #include <stdio.h>
 #define N 50

 int queue[N];
 int front = -1;
 int rear = -1;

 void enqueue()
 {
     int x;
     printf("\nEnter a number:");
     scanf("%d",&x);
     if(((rear + 1) % N) == front)
     {
         printf("\nOverflow");
     }
     else if(front == -1 && rear == -1)
     {
         front = rear = 0;
         queue[rear] = x;
     }
     else
     {
         rear = ((rear + 1) % N);
         queue[rear] = x;
     }
 }

 void dequeue()
 {
     if(front == -1 && rear == -1)
     {
         printf("\nUnderflow");
     }
     else if(front == rear)
     {
         front = rear = -1;
     }
     else
     {
         printf("\nDequeued Element = %d",queue[front]);
         front = ((front + 1) % N);
     }
 }

 void peak()
 {
     if(front == -1 && rear == -1)
     {
          printf("\nUnderflow");
     }
     else
     {
         printf("\nPeak Element = %d",queue[front]);
     }
 }

 void display()
 {
     int i;
     if(front == -1 && rear == -1)
     {
         printf("\nUnderflow");
     }
     else
     {
         printf("\nQueue:-\n");
         while(i != rear)
         {
             printf(" %d |",queue[i]);
             i = ((i+1) % N);
         }
         printf(" %d |",queue[rear]);
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
