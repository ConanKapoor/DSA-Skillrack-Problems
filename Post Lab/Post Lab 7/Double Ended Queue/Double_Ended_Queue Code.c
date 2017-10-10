#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int array[10];
int i=0,b=0,d=0;

struct queue
{
    int data;
    struct queue* next;
};
struct queue* front = NULL, *rear = NULL;

void is_Empty()
{
    if(front == NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        return;
    }
}

void front_Insert()
{
    struct queue *ptr;
    ptr=malloc(sizeof(struct queue));
    scanf("%d",&ptr->data);
    ptr->next=NULL;
    if(front==NULL)
    {
        front = ptr;
        rear = ptr;
    }
    else
    {
        ptr->next=front;
        front=ptr;
    }
}

void rear_Insert()
{
    struct queue* ptr;
    ptr=malloc(sizeof(struct queue));
    ptr->next=NULL;
    scanf("%d",&ptr->data);
    if(rear==NULL)
    {
        rear=ptr;
        front=rear;
    }
    else
    {
        rear->next=ptr;
        rear = ptr;
    }
}
void front_delete()
{
    b++;
    if(front==NULL)
    {
        printf("Queue is empty");
        exit(0);
    }
    if(front==rear)
    {
        array[i]=front->data;
        i++;
        free(front);
        rear=NULL;
    }
    else
    {
        struct queue *ptr;
        ptr=front;
        array[i]=ptr->data;
        i++;
        front = ptr->next;
        free(ptr);
    }
}

void rear_Delete()
{
    d++;
    struct queue *temporary,*ptr;
    temporary=front;
     if(rear==NULL)
    {
        printf("Queue is empty");
        exit(0);
    }
    if(front==rear)
    {
        array[i]=rear->data;
        i++;
        free(rear);
        front=NULL;
    }
    else
    {
        while(temporary->next!=NULL)
        {
            ptr=temporary;
            temporary=temporary->next;
        }
        array[i]=(ptr->next)->data;
        i++;
        ptr->next=NULL;
        rear=ptr;
        free(temporary);
    }
}

void Display()
{
    int x;
    for(x=0;x<i;x++)
    {
        printf("%d\n",array[x]);
    }
    struct queue *temporary;
    temporary=front;
    while(temporary!=NULL)
    {
        printf("%d\n",temporary->data);
        temporary= temporary->next;
    }
}

int main()
{
    char character;
    do{
        scanf("%c",&character);
        switch(character)
        {
            case 'a':front_Insert();
                     break;
            case 'b': front_delete();
                    break;
            case 'c':rear_Insert();
                    break;
            case 'd':rear_Delete();
                    break;
            case 'e': Display();
                    break;
        }
      }
    while(character!='e' || (b==0 && d==0));
    is_Empty();
}
