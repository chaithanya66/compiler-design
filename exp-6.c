#include<stdio.h>
void leftrecursive(char t,char a[10],char b[10])
{
	printf("\nGiven: %c-->%s/%s",t,a,b);
	printf("\nLeftRecursion:");
	printf("\n%c-->%s%c'",t,b,t);
	printf("\n%c'-->%s%c'|e",t,a,t);
}
int main()
{
	char t,a[10],b[10];
	printf("Enter non terminal:");
	scanf("%c",&t);
	printf("\nEnter alpha:");
	scanf("%s",&a);
	printf("\nEnter beta:");
	scanf("%s",&b);
	leftrecursive(t,a,b);
}
