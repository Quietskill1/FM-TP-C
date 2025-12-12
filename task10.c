// /Write a Program to Rotate a matrix by 90 degrees in the clockwise direction in C.
//Run the flip in a function, return pointer to the rotated matrix and print it in main function.
#include <stdio.h>
#include <stdlib.h>
int** rotate(int n, int a[n][n])
{
    int **r=malloc(n*sizeof(int*));
    for (int i=0; i<n; i++)
        r[i]=malloc(n*sizeof(int));
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            r[j][n-1-i]=a[i][j];
    return r;
}

void accept(int n, int a[n][n])
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}
void display(int* r, int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            printf("%d ", r[i*n + j]);
        }
        printf("\n");
    }
}
void display2(int** r, int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            printf("%d ", r[i][j]);
        printf("\n");
    }
}
int main(void)
{
    int n;
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);
    int a[n][n];
    printf("Enter the elements of the matrix:\n");
    accept(n, a);
    int** r=rotate(n, a);
    printf("The original matrix is:\n");
    display((int*)a, n);
    printf("The rotated matrix is:\n");
    display2(r, n);
    return 0;
}