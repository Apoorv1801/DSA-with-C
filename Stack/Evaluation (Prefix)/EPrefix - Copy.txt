 #include <stdio.h>
 #include <string.h>

 float stack[50];
 int top = -1;

 void push(float x)
 {
    stack[++top] = x;
 }

 float pop()
 {
    return(stack[top--]);
 }

 int type(char c)
 {
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return 1;
    else
        return 0;
 }

 int main()
 {
    char prefix[50];
    int len,i;
    float val, op1, op2, r;
    printf("\n Enter Prefix Expression (Without Space): ");
    gets(prefix);
    len = strlen(prefix);
    for(i=len-1;i>=0;i--)
    {
        switch(type(prefix[i]))
        {
            case 0:
                val = prefix[i] - '0';
                push(val);
                break;
            case 1:
                op1 = pop();
                op2 = pop();
            switch(prefix[i])
            {
                case '+':
                    r = op1 + op2;
                    break;
                case '-':
                    r = op1 - op2;
                    break;
                case '*':
                    r = op1 * op2;
                    break;
                case '/':
                    r = op1 / op2;
                    break;
                case '^':
                    r = pow(op1,op2);
                    break;
            }
            push(r);
        }
    }
    printf("\n Result = %.2f", stack[0]);
    return 0;
 }



