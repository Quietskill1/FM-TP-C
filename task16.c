/*
 Implement a recursive function to compress a string by replacing consecutive duplicate characters with 
their count (e.g., aaabbc becomes a3b2c1).
*/
#include <stdio.h>
#include <string.h>
void compress(char str[], int index, int count, char result[], int *resIndex)
{
    if(str[index]=='\0')
    {
        if(count>0)
        {
            result[(*resIndex)++]=str[index-1];
            result[(*resIndex)++]=count+'0';
        }
        result[*resIndex]='\0';
        return;
    }
    if(index==0 || str[index]==str[index-1])
    {
        compress(str, index+1, count+1, result, resIndex);
    }
    else
    {
        result[(*resIndex)++]=str[index-1];
        result[(*resIndex)++]=count+'0';
        compress(str, index+1, 1, result, resIndex);
    }
}
int main()
{
    char str[100], result[200];
    int resIndex=0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; //remove trailing newline
    compress(str, 0, 0, result, &resIndex);
    printf("Compressed string: %s\n", result);
    return 0;
}