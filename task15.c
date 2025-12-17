//Create a recursive function to find the nth term of the Fibonacci series.
// Fibonacci series:...-8, 5, -3, 2, -1, 1, 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...(sum of prev two terms)
#include <stdio.h>
int fibonacci(int n)//works with negative numbers as well
{
    if(n==0)
        return 0;
    else if(n==1 || n==-1)
        return 1;
    else if(n>1)
        return fibonacci(n-1)+fibonacci(n-2);
    else
        return fibonacci(n+2)-fibonacci(n+1);
}
int main(void) 
{
    int n;
    printf("Enter the term number to find in Fibonacci series: ");
    input:
    if(scanf("%d", &n)!=1)
    {
        printf("Invalid input. Please enter an integer.\n");
        while(getchar()!='\n');
        goto input;
    }
    int result = fibonacci(n);
    printf("The %dth term in the Fibonacci series is: %d\n", n, result);
    return 0;
}
