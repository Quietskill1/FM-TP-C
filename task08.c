//Develop a program to swap every two adjacent elements in an array using pointers.
//Pairs start from i=0, ignores i=n-1 if odd number of elements.
#include <stdio.h>
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
void swapAdjacent(int *p, int n)
{
    for(int i=0; i<n-1; i+=2)
    {
        int t = *(p+i);
        *(p+i) = *(p+i+1);
        *(p+i+1) = t;
    }
}
void display(int *p, int n)
{
    printf("Array after swapping adjacent elements:\n");
    for(int i=0; i<n; i++)
    {
        printf("%d ", *(p+i));
    }
    printf("\n");
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
    int *p = a;
    accept(p, n);
    swapAdjacent(p, n);
    display(p, n);
}
