// Write a program to read a file and count the number of characters, words, and lines in a file.
/*
This is a file.
Hello World
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char p[256];
    input:
    printf("Enter the file path: ");
    fgets(p, sizeof(p), stdin);
    p[strcspn(p, "\n")]='\0';//replaces newline character with null character
    FILE *f=fopen(p, "r");
    if (f==NULL)
    {
        printf("Could not open file. Please check the path and try again.\n");
        goto input;
    }
    int cc=0, wc=0, lc=0, in=0;
    char ch;
    while((ch=fgetc(f))!=EOF)
    {
        cc++;
        if(ch==' ' || ch=='\n' || ch=='\t')
            in=0;//end of a word
        else if(in==0)
        {
            in=1;//start of a new word
            wc++;
        }
        if(ch=='\n')
            lc++;
    }
    if(cc>0)
        lc++;
    fclose(f);
    printf("Characters: %d\nWords: %d\nLines: %d\n", cc, wc, lc);
    return 0;
}
