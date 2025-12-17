/*
Take each element of the 4x4 matrix from the user and print it, then add each element from the 4x4 
matrix and print the sum, print the sum of both the diagonals.
*/
#include <stdio.h>
void accept(int arr[4][4])
{
    printf("Enter elements of the 4x4 matrix:\n");
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            printf("Element [%d][%d]: ", i, j);
            input:
            if(scanf("%d", &arr[i][j])!=1)
            {
                printf("Invalid input. Please enter an integer.\n");
                while(getchar()!='\n');
                goto input;
            }
        }
    }
}
void display(int arr[4][4])
{
    printf("The 4x4 matrix is:\n");
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
            printf("%d\t", arr[i][j]);
        printf("\n");
    }
}
void sumAll(int arr[4][4])
{
    int s = 0;
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
            s+=arr[i][j];
    }
    printf("Sum of all elements: %d\n", s);
}
void sumDiagonals(int arr[4][4])
{
    int primarySum = 0, secondarySum = 0;
    for (int i=0; i<4; i++)
    {
        primarySum += arr[i][i];
        secondarySum += arr[i][3-i];
    }
    printf("Sum of primary diagonal: %d\n", primarySum);
    printf("Sum of secondary diagonal: %d\n", secondarySum);
}
int main(void)
{
    int m[4][4];
    accept(m);
    display(m);
    sumAll(m);
    sumDiagonals(m);
    return 0;
}
