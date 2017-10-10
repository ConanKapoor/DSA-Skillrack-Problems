#include<stdio.h>
#include<string.h>
#define MAXSIZE 100

struct stack
{
    char stk[MAXSIZE];
    int top;
};

typedef struct stack STACK;
STACK s;

void push(char alpha);
char pop();

main ()
{
    s.top = -1;
    int i,length=0;
    char string[100],string_new[100];
    scanf("%s",string);
    for(i=0;i<strlen(string);i++)
    {
        if(string[i]>='A' && string[i]<='Z')
        {
            push(string[i]);
        }
        else
        {
            string_new[length]=pop();
            length++;
        }
    }
    for(i=0;i<length;i++)
    {
        printf("%c",string_new[i]);
    }
}

void push(char alpha)
{
    if(s.top==(MAXSIZE-1))
    {
        printf ("Stack is Full\n");
        return;
    }
    else
    {
        s.top = s.top + 1;
        s.stk[s.top] = alpha;
    }
}

char pop()
{
    char pop_alpha;
    if(s.top==-1)
    {
        printf ("Stack is Empty\n");
        return (s.top);
    }
    else
    {
        pop_alpha = s.stk[s.top];
        s.top = s.top - 1;
    }
    return(pop_alpha);
}
