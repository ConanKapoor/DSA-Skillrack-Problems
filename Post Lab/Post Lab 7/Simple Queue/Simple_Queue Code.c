#include<stdio.h>
#include<string.h>
#define MAX 50

char queue[MAX];
int rear=-1;
int front=-1;

void Enqueue(char alpha);
char Dequeue();

main()
{
    int i,length=0;
    char string[100],string_new[100];
    scanf("%s",string);
    for(i=0;i<strlen(string);i++)
    {
        if(string[i]>='A' && string[i]<='Z')
        {
            Enqueue(string[i]);
        }
        else
        {
            string_new[length]=Dequeue();
            length++;
        }
    }
    string_new[length]='\0';
    printf("%s",string_new);

}

void Enqueue(char alpha)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow \n");
    }
    else
    {
        if (front==-1)
        {
            front = 0;
        }
        rear = rear + 1;
        queue[rear]=alpha;
    }
}

char Dequeue()
{
    if (front==-1||front>rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        return queue[front++];
    }
}
