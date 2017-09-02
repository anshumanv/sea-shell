#include <stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include<string.h>

int main()
{
  int result;
  char dir[100];

  printf("Enter the directory name: ");
  fgets(dir,100,stdin);	//gets function giving warning, this will resolve

  result = rmdir(dir);
  if (result != 0)
  {
     perror("Could not remove directory");
     exit(EXIT_FAILURE);
  }

  printf("Directory removed successfully\n");

  return 0;
}
