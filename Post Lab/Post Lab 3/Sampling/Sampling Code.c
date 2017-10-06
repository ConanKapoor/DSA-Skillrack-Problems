#include<stdio.h>
#include <stdlib.h>
struct node
{
    int val,flag;
    struct node *link;
}*head,*last,*new_node;

void get_node()
{
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->link = NULL;
    new_node->flag = 0;
}

int read_node(struct node*List)
{
    int magnitude,counter;
    scanf("%d",&magnitude);
    counter=0;
    for(;List!=NULL;List=List->link)
    {
        if (List->val==magnitude)
        {
            List->flag=List->flag+1;
            counter++;
        }
    }
    if (counter>0)
    {
        return 1;
    }
    else
    {

        new_node->val=magnitude;
        new_node->flag++;
        new_node->link=NULL;
        return 0;
    }
}
void insert_end()
{
    get_node();
    if (new_node==NULL)
    {
        return;
    }

    int check = read_node(head);

    if(check==0)
    {
        last->link=new_node;
        last=new_node;
    }
    else
        return;
}
void sorting(struct node* List)
{
    int temporary,temporary1;
    struct node *pointer,*pointer1;
    pointer = List;
    while(pointer->link!=NULL)
    {
        pointer1=pointer->link;
        while(pointer1!=NULL){
            if (pointer->val > pointer1->val)
            {
                temporary = pointer->val;
                pointer->val=pointer1->val;
                pointer1->val=temporary;

                temporary1=pointer->flag;
                pointer->flag=pointer1->flag;
                pointer1->flag=temporary1;
            }
            pointer1=pointer1->link;
        }
        pointer=pointer->link;
    }
}

int main()
{
    int num,i;
    scanf("%d",&num);
    get_node();
    scanf("%d",&(new_node->val));
    new_node->flag++;
    head = last = new_node;
    for (i=0;i<num-1;i++)
        insert_end();
    sorting(head);

    for (;head!=NULL;head=head->link)
    {
        printf("%d\n%d\n",(head->val),(head->flag));
    }
    return 0;
}
