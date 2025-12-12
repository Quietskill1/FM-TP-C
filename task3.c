//Create a program to calculate electricity bills based on usage slabs.
/*
    Slab        Rate
    <=100       5
    101-300     8
    >300        10
    350 units = (100*5) + (200*8) + (50*10) = 500 + 1600 + 500 = 2600
*/
#include <stdio.h>
int bill(int u)
{
    int tot;
    if(u<=100)
        tot = u * 5;
    else if(u<=300)
        tot = (100 * 5) + (u - 100) * 8;
    else
        tot = (100 * 5) + (200 * 8) + (u - 300) * 10;
    return tot;
}
int main(void)
{
    int x;
    printf("Enter units consumed: ");
    scanf("%d", &x);
    printf("Total bill: Rs.%d", bill(x));
    return 0;
}