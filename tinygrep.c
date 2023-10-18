
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define limit 35

// method to check for special characters
bool containsSpecial(char input, char pattern)
{
  
    return (pattern == '.' || (pattern == '_' && isspace(input)) || input == pattern);
}

int findPattern(char *input, char *pattern, bool choice)
{
    // diff between sizeof and size_t was learned while writing this codeblock.... one is a variable type while the latter is a operator.
    size_t inputLength = strlen(input); // get length of input
    size_t patternLength = strlen(pattern);

    for (size_t i = 0; i <= inputLength - patternLength; i++)
    {
        bool match = true; // initialise to true first

        for (size_t j = 0; j < patternLength; j++) // loop through
        {
            if (!containsSpecial(input[i + j], pattern[j])) // ! means NOT
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
    bool choice; 

    printf("Enter a line of text up to 35 characters in length ->\n");
    fgets(input, sizeof(input), stdin);

    printf("Enter a grepPattern to search for up to 35 characters in length ->\n");
    fgets(pattern, sizeof(pattern), stdin);

    printf("Should text be matched to case-sensitive?\n");
    fgets("%c", choice, stdin);

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

    int matchIndex = findPattern(input, pattern, choice); // must match the 3 parameters declared in the method.

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
