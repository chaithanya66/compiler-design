//Experiment 02
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_IDENTIFIER_LENGTH 31

void checkComment() {
    int c = getchar();
    if (c == '/') {
        int next = getchar();
        if (next == '/') {
            printf("Single-line comment detected\n");
            while ((c = getchar()) != '\n' && c != EOF);
        } else if (next == '*') {
            printf("Multi-line comment detected\n");
            while ((c = getchar()) != EOF) {
                if (c == '*') {
                    if ((c = getchar()) == '/') break;
                }
            }
        } else {
        	
            ungetc(next, stdin);
            ungetc(c, stdin);
        }
    } else {
    	printf("Comment line not detected.\n");
        ungetc(c, stdin);
    }
}

int main() {
    printf("Enter your code: \n");
    checkComment();
    return 0;
}
