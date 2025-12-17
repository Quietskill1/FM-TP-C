//Create a program to calculate electricity bills based on usage slabs.
/*
    Slab        Rate
    <=100       5
    101-300     8
    >300        10
    350 units = (100*5) + (200*8) + (50*10) = 500 + 1600 + 500 = 2600
*/
#include <stdio.h>
float bill(float u)
{
    float tot;
    if(u<=100)
        tot=u*5;
    else if(u<=300)
        tot=(100*5)+(u-100)*8;
    else
        tot=(100*5)+(200*8)+(u-300)*10;
    return tot;
}
int main()
{
    float x;
    input:
    printf("Enter units consumed: ");
    if(scanf("%f", &x)!=1||x<0)
    {
        printf("Invalid input. Please enter a non-negative number.\n");
        while(getchar()!='\n');
        goto input;
    }
    printf("Total bill: Rs.%.2f", bill(x));//%.2f to print only 2 decimal places
    return 0;
}
