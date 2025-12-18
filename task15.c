//Create a recursive function to find the nth term of the Fibonacci series.
// Fibonacci series:... 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...(sum of prev two terms)
#include <stdio.h>
int fibonacci(int n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
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
    int result = fibonacci(n-1);//n-1 because series starts from 0, so nth term is at index n-1
    printf("The %dth term in the Fibonacci series is: %d\n", n, result);
    return 0;
}
