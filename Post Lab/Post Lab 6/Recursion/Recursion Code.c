#include<stdio.h>
#include<stdlib.h>
void g(float x[],int n,int t);
main()
{
    int n,i,t;
    scanf("%d",&n);
    if(n>=2)
    {
        float x[n];
        for(i=0;i<n;i++)
        {
            scanf("%f",&x[i]);
        }
        scanf("%d",&t);
        g(x,n-1,t);
    }
    else
    {
        printf("Invalid input");
    }
}
void g(float x[],int n,int t)
{
    if(n==-1)
    {
        return;
    }
    else if(n==t)
    {
        g(x,n-1,t);
    }

    else
    {
        float temp;
        temp=x[t]*x[n];
        printf("%.0f\n",temp);
        g(x,n-1,t);
    }
}
