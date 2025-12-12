/*Implement a program count the number of vowels and consonants in the given string as well as to 
scramble the characters of a string randomly.*/
//Use srand() with time to seed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
void vowCon(char str[])
{
    int v=0,c=0;
    for(int i=0; str[i]!='\0'; i++)
    {
        char ch=str[i];
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
        {
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
                v++;
            else
                c++;
        }
    }
    printf("Vowels: %d\nConsonants: %d\n",v,c);
}
void scramble(char str[])
{
    int n=strlen(str);
    for(int i=0; i<n; i++)
    {
        int r=rand()%n;
        char temp=str[i];
        str[i]=str[r];
        str[r]=temp;
    }
}
int main(void)
{
    char str[100];
    int v=0,c=0;
    printf("Enter a string: ");
    fgets(str,sizeof(str),stdin);
    str[strcspn(str, "\n")] = '\0'; //remove trailing newline "string compliment span"
    vowCon(str);
    srand(time(0));//ensures different random sequences on each run of rand()
    scramble(str);
    printf("Scrambled string: %s\n",str);
    return 0;
}