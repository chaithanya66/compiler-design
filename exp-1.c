//Experiment 01
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_IDENTIFIER_LENGTH 31

void skipWhitespaceAndComments() {
    int c;
    while ((c = getchar()) != EOF) {
        if (isspace(c)) continue;
        if (c == '/') {
            int next = getchar();
            if (next == '/') {
                while ((c = getchar()) != '\n' && c != EOF);
            } else if (next == '*') {
                while ((c = getchar()) != EOF) {
                    if (c == '*') {
                        if ((c = getchar()) == '/') break;
                    }
                }
            } else {
                ungetc(next, stdin);
                ungetc(c, stdin);
                return;
            }
        } else {
            ungetc(c, stdin);
            return;
        }
    }
}

void processInput() {
    int c;
    while ((c = getchar()) != EOF) {
        skipWhitespaceAndComments();
        if (isalpha(c) || c == '_') { 
            char identifier[MAX_IDENTIFIER_LENGTH + 1];
            int i = 0;
            do {
                if (i < MAX_IDENTIFIER_LENGTH) {
                    identifier[i++] = c;
                }
                c = getchar();
            } while (isalnum(c) || c == '_');
            identifier[i] = '\0';
            ungetc(c, stdin);
            printf("Identifier: %s\n", identifier);
        } else if (isdigit(c)) {
            char number[32];
            int i = 0;
            do {
                number[i++] = c;
                c = getchar();
            } while (isdigit(c));
            number[i] = '\0';
            ungetc(c, stdin);
            printf("Constant: %s\n", number);
        } else if (strchr("+-*/=<>!&|", c)) {
            char op[3] = {c, '\0', '\0'};
            int next = getchar();
            if (strchr("=|&", next)) {
                op[1] = next;
            } else {
                ungetc(next, stdin);
            }
            printf("Operator: %s\n", op);
        }
    }
}

int main() {
    printf("Enter your code: \n");
    processInput();
    return 0;
}
