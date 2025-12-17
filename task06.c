/*Implement a program count the number of vowels and consonants in the given string as well as to 
scramble the characters of a string randomly.*/
//Use srand() with time to seed
//count numbers and special characters as well, make sure to presevre spaces and special characters during scrambling
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
void vowCon(char str[])
{
    int v=0,c=0,n=0,s=0;
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
        else if(ch>='0' && ch<='9')
            n++;
        else if(ch!=' ' && ch!='\n' && ch!='\t')
            s++;
    }
    printf("Vowels: %d\nConsonants: %d\nNumbers: %d\nSpecial Characters: %d\n",v,c,n,s);
}
void scramble(char str[])//perserve spaces and special characters in place
{
    int l=strlen(str);
    for(int i=0;i<l;i++)
    {
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') || (str[i]>='0' && str[i]<='9'))
        {
            int j;
            do
                j=rand()%l;
            while(!((str[j]>='a' && str[j]<='z') || (str[j]>='A' && str[j]<='Z') || (str[j]>='0' && str[j]<='9')));
            //swap str[i] and str[j]
            char t=str[i];
            str[i]=str[j];
            str[j]=t;
        }
    }
}
int main(void)
{
    char str[100];
    printf("Enter a string: ");
    fgets(str,sizeof(str),stdin);
    str[strcspn(str, "\n")] = '\0';//remove trailing newline(searches for \n and replaces with \0)
    vowCon(str);
    srand(time(0));//ensures different random sequences on each run of rand()
    scramble(str);
    printf("Scrambled string: %s\n",str);
    return 0;
}
