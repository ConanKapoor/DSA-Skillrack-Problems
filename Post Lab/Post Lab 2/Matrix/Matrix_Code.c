#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	scanf("%d",&n);
	int array[n][n],temp,i,j,k;
	for(i=0;i<n;i++)
        {
		for(j=0;j<n;j++)
            {
			scanf("%d",&array[i][j]);
            }
        }
	for(i=0;i<n;i++)
        {
		for(j=0;j<n;j++)
            {
			for(k=0;k<n-j-1;k++)
                {
				if(array[i][k]>array[i][k+1] )
                    {
					temp=array[i][k];
				    array[i][k]=array[i][k+1];
				    array[i][k+1]=temp;
                    }
                }
            }
        }
	for(j=0;j<n;j++)
        {
		for(i=0;i<n;i++)
            {
			for(k=0;k<n-i-1;k++)
                {
				if(array[k][j]>array[k+1][j] )
                    {
					temp=array[k][j];
				    array[k][j]=array[k+1][j];
				    array[k+1][j]=temp;
                    }
                }
            }
        }
    for(i=0;i<n;i++)
        {
		for(j=0;j<n;j++)
            {
			printf("%d ",array[i][j]);
            }
		printf("\n");
        }
	return 0;
}
