//Create a program to remove all duplicates from an array of integers.
//Basics of arrays, searching, shifting elements.
#include <stdio.h>
void accept(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
}
int removeDuplicates(int arr[],int n)
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;)
        {
            if(arr[i]==arr[j])
            {
                for(k=j;k<n-1;k++)
                {
                    arr[k]=arr[k+1];
                }
                n--;
            }
            else
            {
                j++;
            }
        }
    }
    return n;
}
int main(void)
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int arr[n];
    accept(arr,n);
    n=removeDuplicates(arr,n);
    printf("Array after removing duplicates: \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}