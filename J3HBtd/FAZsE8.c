#include <stdio.h>
#include <string.h>

// Constraints: 0 <= length of sentence <= 1000

void reverseWord(char *start, char *end)
{
    char temp;
    while (start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void reverseWords(char *str)
{
    char *word_start = str;
    char *temp = str;

    // Reverse individual words
    while (*temp)
    {
        temp++;
        if (*temp == '\0')
        {
            reverseWord(word_start, temp - 1);
        }
        else if (*temp == ' ')
        {
            reverseWord(word_start, temp - 1);
            word_start = temp + 1;
        }
    }

    // Reverse the entire string
    reverseWord(str, temp - 1);
}

int main()
{
    char sentence[1000];

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove the newline character if present
    int len = strlen(sentence);
    if (len > 0 && sentence[len - 1] == '\n')
    {
        sentence[len - 1] = '\0';
    }

    printf("Original sentence: %s\n", sentence);

    reverseWords(sentence);

    printf("Reversed sentence: %s\n", sentence);

    return 0;
}
