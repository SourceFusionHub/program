#include <stdio.h>
#include <string.h>
 
char str[100], sub[100]; //declaring str and char string 
int count = 0, count1 = 0;   
 
void main()
{
    int l, l1, l2;
 
    printf("\nEnter a string : ");
    scanf("%[^\n]s", str); 
 
    l1 = strlen(str);
 
    printf("\nEnter a substring : ");
    scanf(" %[^\n]s", sub);
 
    l2 = strlen(sub);
 
    for (int i = 0; i < l1;) 
    {
        int j = 0;
        count = 0;
        while ((str[i] == sub[j]))
        {
            count++;
            i++;
            j++;
        }
        if (count == l2)
        {
            count1++;                                   
            count = 0;
        }
        else
            i++;
    }    
    printf("%s occurs %d times in %s", sub, count1, str);
}
