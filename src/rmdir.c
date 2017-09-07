#include <stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include<string.h>

int main()
{
  int result;
  char * dir = (char *)malloc(100 * sizeof(char));
	

  printf("Enter the directory name: ");
  fgets(dir,100,stdin);	//gets function giving warning, this will resolve
	dir = strtok(dir, "\n");
	
  result = rmdir(dir);
  if (result != 0)
  {
     perror("Could not remove directory");
     exit(EXIT_FAILURE);
  }

  printf("Directory removed successfully\n");
	
  return 0;
}
