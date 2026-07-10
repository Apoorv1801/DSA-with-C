 #include <stdio.h>
 #define N 50

 int s1[N],s2[N];
 int top1 = -1, top2 = -1;
 int count = 0;

 void push1(int num)
 {
     printf("\nEnter a number:");
     scanf("%d",&num);
     if(top1 == N-1)
     {
         printf("\nOverflow");
     }
     else
     {
         top1++;
         s1[top1] = num;
     }
 }

 void push2(int num)
 {
     printf("\nEnter a number:");
     scanf("%d",&num);
     if(top2 == N-1)
     {
         printf("\nOverflow");
     }
     else
     {
         top2++;
         s2[top2] = num;
     }
 }

 int pop1()
 {
     return s1[top1--];
 }

 int pop2()
 {
     return s2[top2--];
 }

 void enqueue(int x)
 {
     push1(x);
     count++;
 }

 void dequeue()
 {
     int i,a,b;
     if(top1 == -1 && top2 == -1)
     {
         printf("\nUnderflow");
     }
     else
     {
         for(i=0;i<count;i++)
         {
             a = pop1();
             push2(a);
         }
         b = pop2();
         printf("\nDequeued Element = %d",b);
         count--;
         for(i=0;i<count;i++)
         {
             a = pop2();
             push1(a);
         }
     }
 }

 void display()
 {
     int i;
     printf("\nQueue:-\n");
     for(i=0;i<=top1;i++)
     {
         printf(" %d |",s1[i]);
     }
 }

 int main()
 {
     enqueue(2);
     enqueue(5);
     enqueue(-1);
     display();
     dequeue();
     dequeue();
     display();
     return 0;
 }
