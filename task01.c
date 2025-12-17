//Write a program to determine if the sum of three user-input integers is even or odd as well as if the number is prime or composite.
//#include <stdio.h>, main returns an int and has to accept void, scanf("%d",&a) accepts, printf("blabla %d bla bla",a) prints a where %d is
#include <stdio.h>
#include <math.h>
int checkPrime(int num)
{
    int c=0;
    if(num<=1)
        return -1;//1 and below cannot be prime
    float sq=sqrt(num);//optimize by checking up to sqrt(num), create a data member to avoid recalculating every iteration
    for(int i=1;i<=sq;i++)
    {
        if(num%i==0)
            c++;
    }
    if(c>1)
        return 0;
    else
        return 1;
}
int main()
{
    int a, b, c, sum;
    int f=0;
    while(!f)
    {
    printf("Enter three integers: ");
    if(scanf("%d %d %d", &a, &b, &c)==3)
    f=1;
    else
    {
        printf("Invalid input. Please enter three integers.\n");
        while(getchar()!='\n');
    }
    }
    sum=a+b+c;
    if(sum%2==0)
        printf("The sum %d is even", sum);
    else
        printf("The sum %d is odd", sum);
    if(checkPrime(sum)==1)
        printf("\nThe sum %d is a prime number", sum);
    else if(checkPrime(sum)==-1)
        printf("\nThe sum %d is neither a prime nor a composite number", sum);
    else
        printf("\nThe sum %d is a composite number", sum);
    return 0;
}
