//Create a program that converts seconds into hours, minutes, and remaining seconds.
#include <stdio.h>
int main(void)
{
    int s;
    printf("Enter time in seconds: ");
    scanf("%d",&s);
    printf("Time: %d hours, %d minutes, %d seconds",s/3600,(s%3600)/60,s%60);
    return 0;
}