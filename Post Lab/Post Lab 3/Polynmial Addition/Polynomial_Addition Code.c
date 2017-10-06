#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node
{
	int coefficient,exponent;
	struct node *next;
}p;
void get_Data(p **,int,int);
void polynomial(p **,p **,p **,int,int);
void display(p **);
int main()
{
	int a,b,i,value;
	scanf("%d%d",&a,&b);
	p *head1, *head2, *head3;
	head1=NULL;
	head2=NULL;
	head3=NULL;
	for(i=a;i>=0;i--)
	{
		scanf("%d",&value);
		get_Data(&head1,value,i);
	}
	for(i=b;i>=0;i--)
	{
		scanf("%d",&value);
		get_Data(&head2,value,i);
	}
	polynomial(&head1,&head2,&head3,a,b);
	display(&head3);
	return(0);
}
void get_Data(p **add_head,int value,int i)
{
	p *new_node=(p*)malloc(sizeof(p));
	new_node->coefficient=value;
	new_node->exponent=i;
 	new_node->next=NULL;
 	if(*add_head==NULL)
    	*add_head=new_node;
    else
    {
    	p *temporary;
    	temporary=*add_head;
    	while((temporary->next)!=NULL)
 		{
 			temporary=temporary->next;
 		}
 		temporary->next=new_node;
    }
}
void polynomial(p **head_add1,p **head_add2,p **head_add3,int a,int b)
{
	p *temporary1,*temporary2,*temp3;int d,i,k=0;
	temporary1=*head_add1;
	temporary2=*head_add2;
	d=abs(a-b);
	p *array[d];
	if(a>b)
	{
		for(i=1;i<=d;i++)
		{
			array[k++]=temporary1;
			temporary1=temporary1->next;
		}
	}
	if(a<b)
	{
		for(i=1;i<=d;i++)
		{
			array[k++]=temporary2;
			temporary2=temporary2->next;
		}
	}
	do
	{
		p *new_node=(p*)malloc(sizeof(p));
		new_node->exponent=temporary1->exponent;
		new_node->coefficient=temporary1->coefficient + temporary2->coefficient;
		new_node->next=NULL;
		if(*head_add3==NULL)
    		{*head_add3=new_node;}
    	else
    	{
    		temp3=*head_add3;
    		while((temp3->next)!=NULL)
 			{
 				temp3=temp3->next;
 			}
 			temp3->next=new_node;
    	}
    	temporary1=temporary1->next;
    	temporary2=temporary2->next;
	}
	while(temporary1!=NULL);
	for(i=d-1;i>=0;i--)
	{
		p *new_node=(p*)malloc(sizeof(p));
     	new_node->coefficient=array[i]->coefficient;
     	new_node->exponent=array[i]->exponent;
    	new_node->next=*head_add3;
    	*head_add3=new_node;
	}
}
void display(p **head_add3)
{
	p *temporary;
	temporary=*head_add3;
	while(temporary!=NULL)
    {
    	if(temporary->coefficient!=0)
			printf("%d,%d\n",temporary->coefficient,temporary->exponent);
		temporary=temporary->next;
	}
}
