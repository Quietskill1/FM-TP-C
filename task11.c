//Implement Bubble sort or Selection sort on an array based on the input from the user and on the sorted 
//array perform binary search algorithm to find an element
#include <stdio.h>
void accept(int n, int a[n])
{
    for (int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
}
void display(int n, int a[n])
{
    for (int i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void bubSort(int n, int a[n])
{
    for (int i=0; i<n-1; i++)
    {
        for (int j=0; j<n-i-1; j++)
        {
            if (a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
void selSort(int n, int a[n])
{
    for (int i=0; i<n-1; i++)
    {
        int mi=i;
        for (int j=i+1; j<n; j++)
        {
            if (a[j]<a[mi])
                mi=j;
        }
        int temp=a[mi];
        a[mi]=a[i];
        a[i]=temp;
    }
}
int binSearch(int n, int a[n], int k)
{
    int l=0, h=n-1;
    while (l<=h)
    {
        int m=l+(h-l)/2;
        if (a[m]==k)
            return m;
        else if (a[m]<k)
            l=m+1;
        else
            h=m-1;
    }
    return -1;
}
int main(void)
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements:\n");
    accept(n, a);
    int c;
    printf("Choose sorting algorithm:\n1. Bubble Sort\n2. Selection Sort\n");
    scanf("%d", &c);
    if (c==1)
        bubSort(n, a);
    else if (c==2)
        selSort(n, a);
    else
    {
        printf("Invalid choice\n");
        return 1;
    }
    printf("Sorted array:\n");
    display(n, a);
    int k;
    printf("Enter the element to search: ");
    scanf("%d", &k);
    int r=binSearch(n, a, k);
    if (r!=-1)
        printf("Element found at index %d\n", r);
    else
        printf("Element not found\n");
    return 0;
}