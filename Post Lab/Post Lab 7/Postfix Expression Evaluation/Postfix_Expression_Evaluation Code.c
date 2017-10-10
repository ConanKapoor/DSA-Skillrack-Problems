#include<stdio.h>
#include<string.h>
#define MAXSIZE 50

int stack[MAXSIZE];
int top=-1;

void push(int element)
{
    stack[++top]=element;
}

int pop()
{
    return(stack[top--]);
}

main()
{
    char postfix[50],character;
    int i=0,op1,op2;
    scanf("%s",postfix);
    while((character=postfix[i++])!='\0')
    {
        if(isdigit(character))
            push(character-'0');
        else
        {
            op2=pop();
            op1=pop();
            switch(character)
            {
                case '+':push(op1+op2);
                        break;
                case '-':push(op1-op2);
                        break;
                case '*':push(op1*op2);
                        break;
                case '/':push(op1/op2);
                        break;
            }
        }
    }
    printf("%d",stack[top]);
}
