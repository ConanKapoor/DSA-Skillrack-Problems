#include<stdio.h>
#include<stdlib.h>
void insert(float a[],int p,int n,int b);
main()
{
    int n,p,b,i;
    scanf("%d",&n);
    float x[20];
    for(i=0;i<n;i++)
    {
        scanf("%f",&x[i]);
    }
    scanf("%d",&p);
    scanf("%d",&b);
    if(n>0 && p>=0 && p<=n+1)
    {
        insert(x,p,n,b);
        for(i=0;i<n+1;i++)
        {
            printf("%0.0f\n",x[i]);
        }
    }
    else
    {
        printf("Invalid input");
    }
}
void insert(float a[],int p,int n,int b)
{
    int i;
    float temp;
    for(i=n;i>=p;i--)
    {
        temp=a[i-1];
        a[i]=temp;
    }
    a[p]=b;
}
