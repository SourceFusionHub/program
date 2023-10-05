#include<stdio.h>
#include<string.h>
int count_consonants(char s[])
{
    int count=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]!='A'&&s[i]!='E'&&s[i]!='I'&&s[i]!='O'&&s[i]!='U'&&s[i]!='a'&&
        s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u')
        {
            count++;
        }
    }
    return count;
}
int main()
{
    char s[100];
    printf("Enter a string:");
    scanf("%s",s);
    int c=count_consonants(s);
    printf("The number of consonants in a string is = %d \n",c);
    return 0;
}