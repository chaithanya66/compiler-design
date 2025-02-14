#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *input;  // The input string
char lookahead; // The current lookahead character

// Function prototypes
void expr();
void term();
void factor();
void match(char t);

// Function to get the next character in the input stream
void next_char() {
    lookahead = *input++;
}

// Match the current lookahead character with the expected token
void match(char t) {
    if (lookahead == t) {
        next_char();
    } else {
        printf("Syntax Error: Expected '%c', found '%c'\n", t, lookahead);
        exit(1);
    }
}

// Parsing rules for 'expr' ? 'term' { '+' 'term' | '-' 'term' }
void expr() {
    term();
    while (lookahead == '+' || lookahead == '-') {
        next_char();
        term();
    }
}

// Parsing rules for 'term' ? 'factor' { '*' 'factor' | '/' 'factor' }
void term() {
    factor();
    while (lookahead == '*' || lookahead == '/') {
        next_char();
        factor();
    }
}

// Parsing rules for 'factor' ? '(' 'expr' ')' | 'number'
void factor() {
    if (lookahead == '(') {
        next_char();
        expr();
        match(')');
    } else if (isdigit(lookahead)) {
        while (isdigit(lookahead)) {
            next_char();
        }
    } else {
        printf("Syntax Error: Unexpected character '%c'\n", lookahead);
        exit(1);
    }
}

int main() {
    // Read the input expression
    printf("Enter an arithmetic expression: ");
    char buffer[256];
    fgets(buffer, sizeof(buffer), stdin);
    
    // Remove the newline character if present at the end
    char *newline = strchr(buffer, '\n');
    if (newline) {
        *newline = '\0';
    }

    input = buffer;
    next_char();  // Initialize lookahead

    // Parse the expression
    expr();

    // Check if the input has been fully parsed
    if (lookahead == '\0') {
        printf("The input string satisfies the grammar.\n");
    } else {
        printf("Syntax Error: Unexpected character '%c'\n", lookahead);
    }

    return 0;
}
