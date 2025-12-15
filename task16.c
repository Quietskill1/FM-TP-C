/*
 Implement a recursive function to compress a string by replacing consecutive duplicate characters with 
their count (e.g., aaabbc becomes a3b2c1).
*/
#include <stdio.h>
#include <string.h>
void compress(char str[], int i, int c, char r[], int *rid)
{
    if(str[i]=='\0')
    {
        if(c>0)
        {
            r[(*rid)++]=str[i-1];
            r[(*rid)++]=c+'0';
        }
        r[*rid]='\0';
        return;
    }
    if(i==0 || str[i]==str[i-1])
    {
        compress(str, i+1, c+1, r, rid);
    }
    else
    {
        r[(*rid)++]=str[i-1];
        r[(*rid)++]=c+'0';
        compress(str, i+1, 1, r, rid);
    }
}
int main()
{
    char str[100], result[200];
    int resIndex=0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")]='\0';
    compress(str, 0, 0, result, &resIndex);
    printf("Compressed string: %s\n", result);
    return 0;
}