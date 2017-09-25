#include<stdio.h>
main()
{
    int i,j,n,x,y,z;																								//Initializing variables.
    scanf("%d",&n);																									//Scanning the value of n.
    int array[n];																											//Initializing an array of length n.
    for (i=0;i<n;i++)
        {
        scanf("%d",&array[i]);														//Reading the elements.
        }
    z=(array[0]-array[1])*(array[0]-array[1]);			//Taking reference value of z.
    for (i=0;i<n;i++)
        {
        for (j=0;j<n;j++)
            {
            if(((array[i]-array[j])*(array[i]-array[j]))<z && i!=j)
                {
                x=i;														//Copying value of i and j to dummy variable...
                y=j;														//...x and y when distance is least.
                z=(array[x]-array[y])*(array[x]-array[y]);
                }
            }
    }
    printf("(%d,%d)",x,y);								//Printing the closest Pair.
}
