 #include <stdio.h>
 #include <ctype.h>
 #define N 100

 float stack[N];
 int top = -1;

 void push(float stack[], float x)
 {
    if(top==N-1)
    {
        printf("\nOverflow");
    }
    else
    {
        top++;
        stack[top] = x;
    }
 }

 float pop(float stack[])
 {
    float x;
    if(top==-1)
    {
        printf("\nUnderflow");
    }
    else
    {
        x = stack[top];
        top--;
    }
    return x;
 }

 float epost(char exp[])
 {
     int i = 0;
     float op1,op2,val;
     while(exp[i] != 0)
     {
         if(isdigit(exp[i]))
         {
             push(stack,(float)(exp[i] - '0'));
         }
         else
         {
             op2 = pop(stack);
             op1 = pop(stack);
             switch(exp[i])
             {
                case '+':
                    val = op1 + op2;
                    break;
                case '-':
                    val = op1 - op2;
                    break;
                case '*':
                    val = op1 * op2;
                    break;
                case '/':
                    val = op1 / op2;
                    break;
                case '^':
                    val = pow(op1,op2);
                    break;
             }
             push(stack,val);
         }
         i++;
     }
     return (pop(stack));
 }

 int main()
 {
    float val;
    char exp[100];
    printf("\n Enter Postfix Expression (Without Space): ");
    gets(exp);
    val = epost(exp);
    printf("\n Value of the postfix expression = %.2f", val);
    return 0;
 }

