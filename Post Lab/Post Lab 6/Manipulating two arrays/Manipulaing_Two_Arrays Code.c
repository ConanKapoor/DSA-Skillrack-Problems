#include<stdio.h>
#include<stdlib.h>
int part_a(int x[],int y[],int n);
int part_b(int x[],int y[],int n);
int part_c(int x[],int y[],int n);
main()
{
    int n,i;
    scanf("%d",&n);
    int x[n],y[n];
    if (n>0)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&x[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&y[i]);
        }
    printf("%d\n",part_a(x,y,n));
    printf("%d\n",part_b(x,y,n));
    printf("%d\n",part_c(x,y,n));
    }
    else
    {
        printf("Invalid input");
    }
}
int part_a(int x[],int y[],int n)
{
    int i,j,Sum=0,Result=0;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            Sum+=y[j];
        }
    Result+=x[i]*Sum;
    Sum=0;
    }
    return Result;
}
int part_b(int x[],int y[],int n)
{
    int i,j,Sum1=0,Sum2=0,Result=0;
    for(i=0;i<n;i++)
    {
        Sum1+=x[i];
        for(j=i;j<n;j++)
        {
            Sum2+=y[j];
        }
        Result+=Sum1*Sum2;
        Sum2=0;
    }
    return Result;
}
int part_c(int x[],int y[],int n)
{
    int i,j,Sum1=0,Sum2=0,Result=0;
    for(i=0;i<n-1;i++)
    {
        Sum1+=x[i];
        for(j=i+1;j<n;j++)
        {
            Sum2+=y[j];
        }
        Result+=Sum1*Sum2;
        Sum2=0;
    }
    return Result;
}
