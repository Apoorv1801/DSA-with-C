 #include <stdio.h>
 #include <ctype.h>
 #include <string.h>
 #define N 100

 char stack[N];
 int top = -1;

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

 void itpost(char source[], char target[])
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
                while( (top != -1) && (stack[top]!= '(') && (priority(stack[top]) >= priority(source[i])))
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
            printf("\n Incorrect Element In Expression");
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
    char infix[100], postfix[100];
    printf("\nEnter Infix Expression (Without Space) : ");
    gets(infix);
    strcpy(postfix, "");
    itpost(infix, postfix);
    printf("\nPostfix :-\n ");
    puts(postfix);
    return 0;
 }
