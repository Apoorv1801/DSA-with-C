 #include <stdio.h>

 char stack[100];
 int top = -1;

 void push(char x)
 {
     stack[++top] = x;
 }

 char pop()
 {
     if(top == -1)
     {
         printf("\nUnderflow");
     }
     else
     {
         return stack[top--];
     }
 }

 int priority(char x)
 {
     if(x == '(')
            return 0;
     if(x == '+'|| x == '-')
            return 1;
     if(x == '*'|| x == '/')
            return 2;
     if(x == '^')
            return 3;

 }

 int main()
 {
     char exp[100];
     char * e, x;
     printf("\nEnter the expression (Without Space):");
     scanf("%s",exp);
     e = exp;
     printf("\nPostfix :-\n");
     while(*e != '\0')
     {
         if(isalnum(*e))
            printf("%c",*e);
         else if (*e == '(')
            push(*e);
         else if (*e == ')')
         {
             while((x = pop()) != '(')
             {
                 printf("%c",x);
             }
         }
         else
         {
             if(priority(*e) == 3)
             {
                push(*e);
             }
             else
             {
                while(priority(stack[top]) >= priority(*e))
                    printf("%c",pop());
                push(*e);
             }
          }
         e++;
     }

     while(top != -1)
     {
         printf("%c",pop());
     }
 return 0;
 }
 // Infix : K+L-M*N+(O^P)*W/U/V*T+Q^J^A   [NEVER GIVE UP]
