/*
LAB 2 ASSIGNMENT - TINYGREP
Student ID: 2300411
Name: Augustine Chan Yi Ren
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define limit 35

// method to check for special characters
bool containSpecial(char input, char pattern)
{
    return (pattern == '.' || (pattern == '_' && isspace(input)) || input == pattern);
}

int findPattern(char *input, char *pattern, bool choice)
{
    size_t inputLength = strlen(input);
    size_t patternLength = strlen(pattern);

    for (size_t i = 0; i <= inputLength - patternLength; i++)
    {
        bool match = true; // initialise to true first

        for (size_t j = 0; j < patternLength; j++)
        {
            if (!containSpecial(input[i + j], pattern[j]))
            {
                match = false;
                break;
            }
        }
        if (match)
        {
            return (int)i;
        }
    }
    return -1;
}

int main()
{
    char input[limit]; // set limit to 35
    char pattern[limit];
    bool choice; // Y or N, so opt for boolean type?

    printf("Enter a line of text up to 35 characters in length ->\n");
    fgets(input, sizeof(input), stdin);

    printf("Enter a grepPattern to search for up to 35 characters in length ->\n");
    fgets(pattern, sizeof(pattern), stdin);

    printf("Should text be matched to case-sensitive?\n");
    scanf(" %c", &choice);

    size_t inputLength = strlen(input);
    size_t patternLength = strlen(pattern);

    if (inputLength > 0 && input[inputLength - 1] == '\n')
    {
        input[inputLength - 1] = '\0';
    }

    if (patternLength > 0 && pattern[patternLength - 1] == '\n')
    {
        pattern[patternLength - 1] = '\0';
    }

    int matchIndex = findPattern(input, pattern, (choice)); // must match the 3 parameters declared in the method.

    if (matchIndex != -1)
    {
        printf("Matches at position %d\n", matchIndex);
    }
    else
    {
        printf("No match\n");
    }

    return 0;
}
