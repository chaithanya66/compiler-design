#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isValidIdentifier(char* str) {
    if (!isalpha(str[0]) && str[0] != '_') {
        return 0; 
    }

    if (str[1] == '\0') {
        return 1;
    } else if (!isalnum(str[1]) && str[1] != '_') {
        return 0; 
    } else {
        return isValidIdentifier(str + 1);
    }
}

int main() {
    char identifier[100];

    printf("Enter an identifier: ");
    scanf("%s", identifier);

    if (isValidIdentifier(identifier)) {
        printf("'%s' is a valid identifier.\n", identifier);
    } else {
        printf("'%s' is not a valid identifier.\n", identifier);
    }

    return 0;
}
