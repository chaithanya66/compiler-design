#include <stdio.h>

int main() 
{
  char input[1000]; 
  int Count = 0;
  int lineCount = 0;
  int i = 0;

  printf("Enter the input string: ");
  fgets(input, sizeof(input), stdin); 

  while (input[i] != '\0') 
  {
    if (input[i] == ' ' || input[i] == '\t') 
	{
      Count++;
    } else if (input[i] == '\n') 
	{
      lineCount++;
    }
    i++;
  }

  printf("Number of whitespaces: %d\n",Count);
  printf("Number of newline characters: %d\n", lineCount);

  return 0;
}
