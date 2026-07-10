 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
 #define N 100

 char stack[N];
 char infix[100], postfix[100], temp[100];
 int top = -1;

 void reverse(char str[])
 {
     int len, i = 0, j = 0;
     len = strlen(str);
     j = len - 1;
     while(j>=0)
     {
         if(str[j] == '(')
         {
             temp[i] = ')';
         }
         else if(str[j] == ')')
         {
             temp[i] = '(';
         }
         else
         {
             temp[i] = str[j];
             i++;
             j--;
         }
     }
     temp[i] = '\0';
 }
 void push(char stack[], char x)
 {
    if(top == N-1)
        printf("\nOverflow");
    else
    {
        top++;
        stack[top] = x;
    }
 }

 char pop(char stack[])
 {
    char x;
    if(top==-1)
        printf("\nUnderflow");
    else
    {
        x = stack[top];
        top--;
    }
    return x;
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

 void itpre(char source[], char target[])
 {
    int i=0, j=0;
    char temp;
    while(source[i]!='\0')
    {
        if(source[i]=='(')
        {
            push(stack,source[i]);
            i++;
        }
        else if(source[i] == ')')
        {
            while((top != -1) && (stack[top]!='('))
            {
                target[j] = pop(stack);
                j++;
            }
            if(top == -1)
            {
                printf("\n Incorrect Expression");
                exit(1);
            }
            temp = pop(stack);//remove left parenthesis
            i++;
        }
        else if(isalnum(source[i]))
        {
            target[j] = source[i];
            j++;
            i++;
        }
        else if (source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/' || source[i] == '^')
        {
            if(priority(source[i]) == 3)
            {
                push(stack,source[i]);
                i++;
            }
            else
            {
                while( (top != -1) && (stack[top]!= '(') && (priority(stack[top]) > priority(source[i])))
                {
                    target[j] = pop(stack);
                    j++;
                }
                push(stack, source[i]);
                i++;
            }
        }
        else
        {
            printf("\n INCORRECT ELEMENT IN EXPRESSION");
            exit(1);
        }
    }
    while((top != -1) && (stack[top]!='('))
    {
        target[j] = pop(stack);
        j++;
    }
    target[j]='\0';
 }

 int main()
 {
    printf("\nEnter Infix Expression (Without Space):");
    gets(infix);
    reverse(infix);
    strcpy(postfix, "");
    itpre(temp,postfix);
    strcpy(temp,"");
    reverse(postfix);
    printf("\nPrefix:- \n");
    puts(temp);
    return 0;
 }
 // Q. - A*B+C/D  Ans. - +*AB/CD (Try)
 // NOTE :- Limitation - Infix should not contain any parenthesis
