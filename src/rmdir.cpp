#include <stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include<string.h>

int main()
{
  int result;
  char dir[50];

  printf("Enter the directory name: ");
  gets(dir);

  result = rmdir(dir);
  if (result != 0)
  {
     perror("Could not remove directory");
     exit(EXIT_FAILURE);
  }

  printf("Directory removed successfully\n");

  return 0;
}
