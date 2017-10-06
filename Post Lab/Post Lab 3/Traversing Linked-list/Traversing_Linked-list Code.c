#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}a;
void Data_Enter(a **,int);
void Node_removal(a **,int,int);
void display(a **);
int main()
{
	int n,i,value,A,B;
	scanf("%d",&n);
	a *head;
	head=NULL;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&value);
		Data_Enter(&head,value);
	}
	scanf("%d",&A);
	scanf("%d",&B);
	if(A<=0 || B<=0)
	{
		printf("Invalid input");
		exit(0);
	}
	Node_removal(&head,A,B);
	display(&head);
	return(0);
}

void Node_removal(a **add_head,int A,int N)
{
	int i,counter1;
	a *temporary1, *Delete, *temporary2;
	temporary1=*add_head;
	while(1==1)
	{
		counter1=1;
		while((temporary1->next)!=NULL && counter1!=A)
		{
			temporary1=temporary1->next;
			counter1++;
		}
		if((temporary1->next)==NULL)
			break;
		for(i=1;i<=B;i++)
		{
			Delete=temporary1->next;
			temporary2=Delete->next;
			free(Delete);
			temporary1->next=temporary2;
			if((temporary1->next)==NULL)
				break;
		}
		if((temporary1->next)==NULL)
			break;
		temporary1=temporary1->next;
	}
}

void Data_Enter(a **add_head,int value)
{
	a *new_node=(a*)malloc(sizeof(a));
	new_node->data=value;
 	new_node->next=NULL;
 	if(*add_head==NULL)
    	*add_head=new_node;
    else
    {
    	a *temporary;
    	temporary=*add_head;
    	while((temporary->next)!=NULL)
 		{
 			temporary=temporary->next;
 		}
 		temporary->next=new_node;
    }
}

void display(a **add_head)
{
	a *temporary;
	temporary=*add_head;
	while(temporary!=NULL)
    {
		printf("%d\n",temporary->data);
		temporary=temporary->next;
	}
}
