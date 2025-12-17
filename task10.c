//Write a Program to Rotate a matrix by 90 degrees in the clockwise direction in C.
//Run the flip in a function, return pointer to the rotated matrix and print it in main function.
#include <stdio.h>
#include <stdlib.h>
int** rotate(int m, int n, int a[m][n])
{
    int c=0;
    allocate:
    int **r=malloc(n*sizeof(int*));
    if (r==NULL)
    {
        if(c<=3)
        {
        printf("Memory allocation failed. Retrying.\n");
        c++;
        goto allocate;
        }
        else
        {
            printf("Memory allocation failed after 3 attempts. Exiting\n");
            exit(1);
        }
    }
    for (int i=0; i<n; i++)
    {
        r[i]=malloc(m*sizeof(int));
        if (r[i]==NULL)
        {
            if(c<=3)
            {
            printf("Memory allocation failed. Retrying.\n");
            c++;
            goto allocate;
            }
            else
            {
                printf("Memory allocation failed after 3 attempts. Exiting\n");
                exit(1);
            }
        }
    }
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            r[j][m-1-i]=a[i][j];
        }
    }
    return r;
}
void accept(int m, int n, int a[m][n])
{
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            input:
            if(scanf("%d", &a[i][j])!=1)
            {
                printf("Invalid input. Please enter an integer.\n");
                while(getchar()!='\n');
                goto input;
            }
        }
    }
}
void display(int m, int n, int a[m][n])
{
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}
void display2(int** r, int m, int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            printf("%d ", r[i][j]);
        printf("\n");
    }
}
int main(void)
{
    int n,m;
    input1:
    printf("Enter number of rows and columns of the matrix: ");
    if(scanf("%d %d", &m, &n)!=2||m<=0||n<=0)
    {
        printf("Invalid input. Please enter two positive integers.\n");
        while(getchar()!='\n');
        goto input1;
    }
    int a[m][n];
    printf("Enter elements of the matrix:\n");
    accept(m, n, a);
    printf("Original matrix:\n");
    display(m, n, a);
    int** r=rotate(m, n, a);
    printf("Matrix after 90 degree clockwise rotation:\n");
    display2(r, m, n);
    return 0;
}
