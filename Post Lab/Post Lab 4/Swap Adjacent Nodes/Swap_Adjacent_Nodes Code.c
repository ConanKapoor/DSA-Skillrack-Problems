#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}a;
int n;
void insertEnd(a **,a **,int);
void swap(a *);
void display(a *,a*);
int main()
{
	int i,val;
	a *head,*tail;
	head=tail=NULL;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&val);
		insertEnd(&head,&tail,val);
	}
	swap(head);
	display(head,tail);
	return(0);
}
void insertEnd(a **head1,a **tail1,int val)
{
	a *newnode=(a*)(malloc(sizeof(a)));
	newnode->data=val;
	if(*head1==NULL)
	{
		*head1=newnode;
		*tail1=newnode;
		newnode->next=*head1;
		newnode->prev=*tail1;
	}
	else
	{
		newnode->next=*head1;
		(newnode->prev)=*tail1;
		((*tail1)->next)=newnode;
		*tail1=newnode;
	}
}
void swap(a *head1)
{
	int i,t;a *temp;
	temp=head1;
	for(i=1;i<=((n%2==0)?(n/2):((n-1)/2));i++)
	{
		t=temp->data;
		temp->data=temp->next->data;
		temp->next->data=t;
		temp=temp->next->next;
	}
}
void display(a *head1,a *tail1)
{
    while(head1!=tail1)
    {
    	printf("%d\n",head1->data);
    	head1=head1->next;
    }
    printf("%d\n",head1->data);
}
