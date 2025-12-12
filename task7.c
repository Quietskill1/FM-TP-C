//Write a program to find the second-largest element in an array using pointers.
//Search twice, find largest, compare and find second largest in second pass.
#include <stdio.h>
void accept(int *p, int n)
{
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", p + i);
    }
}
int largest(int *p, int n)
{
    int l = *(p);
    for(int i = 1; i < n; i++)
    {
        if(*(p + i) > l)
        {
            l = *(p + i);
        }
    }
    return l;
}
int secondLargest(int *p, int n)
{
    int l = largest(p, n);
    int sl = -2147483648; // Initialize to minimum integer value
    for(int i = 0; i < n; i++)
    {
        if(*(p + i) != l && *(p + i) > sl)
        {
            sl = *(p + i);
        }
    }
    return sl;
}
int main(void)
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    int *p = a;
    accept(p, n);
    int sl = secondLargest(p, n);
    if(sl != -2147483648)
        printf("Second largest element: %d\n", sl);
    else
        printf("There is no second largest element.\n");
}