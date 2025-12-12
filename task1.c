//Write a program to determine if the sum of three user-input integers is even or odd as well as if the number is prime or composite.
//#include <stdio.h>, main returns an int and has to accept void, scanf("%d",&a) accepts, printf("blabla %d bla bla",a) prints a where %d is
#include <stdio.h>
bool checkPrime(int num)
{
    int c=0;
    if(num <= 1)
    return false;
    for(int i=1;i<=num/2;i++)
    {
        if(num%i==0)
            c++;
    }
    if(c>1)
        return false;
    else
        return true;
}
int main(void)
{
    int a, b, c, sum;
    printf("Enter thee integers: ");
    scanf("%d %d %d", &a,&b,&c);
    sum = a + b + c;
    if(sum%2==0)
        printf("The sum %d is even", sum);
    else
        printf("The sum %d is odd", sum);
    if(checkPrime(sum))
        printf("\nThe sum %d is a prime number", sum);
    else
        printf("\nThe sum %d is not a prime number", sum);
    return 0;
}