## Text Pattern Search

This C program performs a search within a line of text for a specific pattern. It checks for the existence of a pattern within the provided input line.

### Program Overview:

#### Macros:
- `limit`: Defines the maximum length for input and pattern strings (set to 35 characters).

#### Functionality:

1. **Input**:
    - User inputs a line of text (up to 35 characters in length).
    - User inputs a pattern to search for within the text (up to 35 characters in length).
    - User specifies whether the text matching should be case-sensitive or not.

2. **Pattern Search**:
    - The program matches the pattern within the text and displays the position of the match if found.
    - The search can be case-sensitive based on user choice.

### Code Details:

- **Pattern Matching**:
    - The code uses a function `findPattern()` to search for the specified pattern within the input text.
    - It checks for matches and returns the index position if a match is found, otherwise, it returns -1.

- **Input Handling**:
    - The program reads user inputs using `fgets()` to handle strings.
    - Removes the newline character from the input strings for accurate processing.

### Example Output:

```
Enter a line of text up to 35 characters in length ->
[User inputs a line of text]

Enter a grepPattern to search for up to 35 characters in length ->
[User inputs a pattern to search for]

Should text be matched to case-sensitive? (Y/N)
[User specifies case-sensitivity]

[Output displays either "Matches at position X" or "No match" based on search results.]
```
