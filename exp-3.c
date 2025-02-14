#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isOperator(char ch) {
    // Check if the character is one of the four operators
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

void lexicalAnalyzer(const char *input) {
    int i = 0;
    int len = strlen(input);

    printf("Analyzing input: %s\n", input);

    // Loop through each character of the input
    while (i < len) {
        if (isOperator(input[i])) {
            printf("Operator found: %c\n", input[i]);
        }
        else if (isspace(input[i])) {
            // Skip white spaces
            i++;
            continue;
        }
        else {
            printf("Invalid character: %c\n", input[i]);
            return;  // Exit on invalid character
        }
        i++;
    }

    printf("Analysis complete.\n");
}

int main() {
    const char *input = "+ - * /";  // Example input with operators

    lexicalAnalyzer(input);

    return 0;
}
