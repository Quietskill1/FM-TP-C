/*
Write a C program to print equilateral triangle or Pyramid star pattern series of n rows using. For eg n=5. 
  * 
 ** 
 *** 
**** 
***** 
*/
//print two right triangles side by side?
#include <stdio.h>
int main(void)
{
    int n, i, j;
    printf("Enter number of rows: ");
    input:
    if(scanf("%d", &n)!=1||n<=0)
    {
        printf("Invalid input. Please enter a positive integer.\n");
        while(getchar()!='\n');
        goto input;
    }
    for(i=1; i<=n; i++)
    {
        for (int j=n-(i/2);j>=0;j--)//note the example shows isoceles not equilateral
        {
            printf(" ");
        }
        for (int j=1;j<=i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
