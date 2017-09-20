#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define size 10
char infix[size],postfix[size],stack[size];
int top=-1;
int precedence(char ch);
char pop();
char topelement();
void push(char ch);
int braces(char *);
int main()
{
    char ele,elem,st[2];
    int prep,pre,popped,j=0,i;
    strcpy(postfix," ");
    scanf("%s",infix);
    for(i=0;infix[i]!='\0';++i)
    {
        if(infix[i]!='(' && infix[i]!=')' && (isalpha(infix[i])==0))
            postfix[j++]=infix[i];
        else if(infix[i]=='(')
        {
            elem=infix[i];
            push(elem);
        }
        else if(infix[i]==')')
        {
            while((popped=pop())!='(')
                    postfix[j++]=popped;
        }
        else
        {
            elem=infix[i];
            pre=precedence(elem);
            ele=topelement();
            prep=precedence(ele);
            if(pre>prep)
                push(elem);
            else
            {
                while(prep>=pre)
                {
                    if(ele=='#')
                        break;
                    popped=pop();
                    ele=topelement();
                    postfix[j++]=popped;
                    prep=precedence(ele);
                }
                push(elem);
            }
     }
    }
while((popped=pop())!='#')
    postfix[j++]=popped;
postfix[j]='\0';
printf("%s",postfix);
return 0;
}
int precedence(char ch)
{
    switch(ch)
    {
        case '^':return 5;
        case '/':return 4;
        case '*':return 3;
        case '+':return 2;
        case '-':return 1;
        default:return 0;
    }
}
char pop()
{
    char ret;
    if(top!=-1)
    {
        ret=stack[top];
        top--;
        return ret;
    }
    else
        return '#';
}
char topelement()
{
    char ch;
    if(top!=-1)
        ch=stack[top];
    else ch='#';
        return ch;
}
void push(char ch)
{
    if(top!=size-1)
    {
        top++;
        stack[top]=ch;
    }
}
