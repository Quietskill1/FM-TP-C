//Implement Bubble sort or Selection sort on an array based on the input from the user and on the sorted 
//array perform binary search algorithm to find an element
#include <stdio.h>
void accept(int n, int a[n])
{
    for (int i=0; i<n; i++)
    {
        input:
        if(scanf("%d", &a[i])!=1)
        {
            printf("Invalid input. Please enter an integer.\n");
            while(getchar()!='\n');
            goto input;
        }
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
void binSearch(int n, int a[n], int k)//if multiple occurrences, print all indices
{
    int l=0, r=n-1, found=0;
    while (l<=r)
    {
        int m=l+(r-l)/2;
        if (a[m]==k)
        {
            found=1;
            printf("Element %d found at index %d\n", k, m);
            //check for multiple occurrences on left side
            int lm=m-1;
            while (lm>=0 && a[lm]==k)
            {
                printf("Element %d found at index %d\n", k, lm);
                lm--;
            }
            //check for multiple occurrences on right side
            int rm=m+1;
            while (rm<n && a[rm]==k)
            {
                printf("Element %d found at index %d\n", k, rm);
                rm++;
            }
            break;
        }
        else if (a[m]<k)
            l=m+1;
        else
            r=m-1;
    }
    if (!found)
        printf("Element %d not found in the array.\n", k);
}
int main(void)
{
    int n;
    printf("Enter the number of elements: ");
    input1:
    if((scanf("%d", &n))!=1||n<=0)
    {
        printf("Invalid input. Please enter a positive integer.\n");
        while(getchar()!='\n');
        goto input1;
    }
    int a[n];
    printf("Enter the elements:\n");
    accept(n, a);
    int c;
    printf("Choose sorting algorithm:\n1. Bubble Sort\n2. Selection Sort\n");
    input2:
    if(scanf("%d", &c)!=1)
    {
        printf("Invalid input. Please enter 1 or 2.\n");
        while(getchar()!='\n');
        goto input2;
    }
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
    input3:
    if(scanf("%d", &k)!=1)
    {
        printf("Invalid input. Please enter an integer.\n");
        while(getchar()!='\n');
        goto input3;
    }
    binSearch(n, a, k);
    return 0;
}
