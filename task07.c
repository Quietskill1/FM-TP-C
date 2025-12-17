//Write a program to find the second-largest element in an array using pointers.
//Search twice, find largest, compare and find second largest in second pass.
#include <stdio.h>
#include <limits.h>//for min int on system
void accept(int *p, int n)
{
    printf("Enter %d elements:\n", n);
    for(int i=0; i<n; i++)
    {
        input:
        if(scanf("%d", p+i)!=1)
        {
            printf("Invalid input. Please enter an integer.\n");
            while(getchar()!='\n');
            goto input;
        }
    }
}
int largest(int *p, int n)
{
    int l=*(p);
    for(int i=1; i<n; i++)
    {
        if(*(p+i)>l)
            l=*(p+i);
    }
    return l;
}
int secondLargest(int *p, int n)
{
    int l=largest(p, n);
    int sl, f=-1;
    for(int i=0; i<n; i++)
    {
        if(*(p+i)<l)
        {
            if(f==-1)//avoids uninitialized sl
            {
                sl=*(p+i);
                f=0;
            }
            else if(*(p+i)>sl)
            {
                sl=*(p+i);
                f=i;
            } 
        }
    }
    return f;
}
int main(void)
{
    int n;
    printf("Enter number of elements: ");
    input:
    if(scanf("%d", &n)!=1||n<=0)
    {
        printf("Invalid input. Please enter a positive integer.\n");
        while(getchar()!='\n');
        goto input;
    }
    int a[n];
    int *p=a;
    accept(p, n);
    int f=secondLargest(p, n);
    if(f!=-1)
        printf("Second largest element: %d\n", *(p+f));
    else
        printf("There is no second largest element.\n");
    return 0;
}
