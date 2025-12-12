//Create a program to simulate a simple login system with 3 attempts to enter the correct password.
//Store pw in a string, compare user i/p to stored pw, count the attempts, exit after 3
//Strings in C are char arrays, use strcmp to compare strings. char '\0' is string terminator.
//System.exit(0) equivalent in C is exit(0) from stdlib.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
bool compare(char a[], char b[])
{
    if(strcmp(a,b)==0)
        return true;
    return false;
}
int main(void)
{
    char spw[] = "miata?";
    char ipw[50];
    int c=0;
    while(true)
    {
        printf("Enter password: ");
        scanf("%s", ipw);
        if(compare(spw, ipw))
        {
            printf("Access Granted");
            break;
        }
        else
        {
            c++;
            printf("Incorrect Password.");
            if(c==3)
            {
                printf("3 unsuccessful attempts.\nExiting...");
                exit(0);
            }
            else
                printf("Incorrect password.\nYou have %d attemp(s) remaining. Try Again.\n", 3-c);
        }
    }
}
