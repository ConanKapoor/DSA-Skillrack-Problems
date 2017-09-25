#include<stdio.h>

int binarySearch(int array[],int input,int low,int high)
{
    if(high<=low)
        {
        return(input<array[low])?(low+1):low;
        }
    int mid=(low+high)/2;
    if(input==array[mid])
        {
        return mid+1;
        }
    if(input<array[mid])
        {
        return binarySearch(array,input,mid+1,high);
        }
    return binarySearch(array,input,low,mid-1);
}

void insertionSort(int array[],int n)
{
    int i,location,j,k,term;
    for(i=1;i<n;i++)
        {
        j=i-1;
        term=array[i];
        location=binarySearch(array,term,0,j);
        while(j>=location)
            {
            array[j+1]=array[j];
            j--;
            }
        array[j+1]=term;
        }
}

int main()
{
    int n,i;
    scanf("%d",&n);
    int array[n];
    for(i=0;i<n;i++)
        {
        scanf("%d",&array[i]);
        }
    insertionSort(array,n);
    for(i=0;i<n;i++)
        {
        printf("%d\n",array[i]);
        }
    return 0;
}
