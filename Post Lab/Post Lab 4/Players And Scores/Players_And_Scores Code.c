#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[10];
    int runs;
    struct node* prev, *next;
}*head, *last, *temp, *new_node;

void getnode(){
    //printf("executed1\n");
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node==NULL){
        printf("error\n");
        return;
    }
    //printf("executed2\n");
    new_node->next = NULL;
    new_node->prev = NULL;
    scanf("%s", new_node->name);
    scanf("%d", &new_node->runs);
}

void insert()
{
    getnode();
    if(head==NULL){
        head = last = new_node;
        return;
    }
    temp = head;
    while(temp!=NULL && temp->runs >= new_node->runs){
        temp = temp->next;
    }
    if(temp==head){
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        return;
    }
    if(temp==NULL){
        last->next = new_node;
        new_node->prev = last;
        last = new_node;
        return;
    }
    (temp->prev)->next = new_node;
    new_node->next = temp;
    new_node->prev = (temp->prev);
    temp->prev = new_node;
}

void part_a()
{
    temp = head;
    while(temp!=NULL){
        printf("%s\n%d\n", temp->name, temp->runs);
        temp = temp->next;
    }
}

void part_b(char refer[10])
{
    printf("%s\n", refer);
    temp = head;
    int value;
    while(temp!=NULL){
        if(!strcmp(temp->name, refer)){
            value = temp->runs;
            break;
        }
        temp = temp->next;
    }
    temp = head;
    while(temp!=NULL){
        if(temp->runs==value)
            if(strcmp(temp->name, refer))
                printf("%s\n", temp->name);
        temp = temp->next;
    }
}

void deletion(int refer)
{
    temp = last;
    while(temp->runs < refer){
        struct node* delnode = temp;
        (temp->prev)->next = NULL;
        temp = temp->prev;
        free(delnode);
    }
    last = temp;
}

void part_c(int refer)
{
    deletion(refer);
    part_a();
}

int main()
{
    char choice[10];
    do{
        insert();
        scanf(" %s", choice);
    }while(choice[0]=='y');
    char word[10];
    scanf(" %s", word);
    int limit;
    scanf("%d", &limit);
    part_a();
    part_b(word);
    part_c(limit);
}
