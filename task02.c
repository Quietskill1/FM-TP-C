//Create a program that converts seconds into hours, minutes, and remaining seconds.
#include <stdio.h>
int main(void)
{
    int s;
    input:
    printf("Enter time in seconds: ");
    if (scanf("%d", &s)!=1||s<0)
    {
        printf("Invalid input. Please enter a non-negative integer.\n");
        while(getchar()!='\n');
        goto input;
    }
    printf("Time: %d hours, %d minutes, %d seconds",s/3600,(s%3600)/60,s%60);
    return 0;
}
