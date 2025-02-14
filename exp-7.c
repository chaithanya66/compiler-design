#include <stdio.h>
#include <string.h>

void left_factoring(char t, char a[10], char b[10]) {
    printf("\nGiven: %c --> %s / %s", t, a, b);
    printf("\nLeft Factoring:");
    printf("\n%c --> %c'%s", t, t, &a[1]);
    printf("\n%c' --> %c%s | %s", t, t, &b[1], "e");
}

int main() {
    char t, a[10], b[10];
    printf("Enter non-terminal: ");
    scanf(" %c", &t);
    printf("\nEnter alpha: ");
    scanf("%s", a);
    printf("\nEnter beta: ");
    scanf("%s", b);
    left_factoring(t, a, b);
    return 0;
}
