#include <stdio.h>
#include <string.h>
#include "pwd.c"

int main() {
	
	//Parent loop for our shell
	while(1) {
		printf("%s", "myshell$ > ");		// Printing shell name in each iteration
		char ipcmd[100];					// Input command string
		gets(ipcmd);						// Reading input command string
		
		if (strcmp(ipcmd, "pwd") == 0) {
			char *path = print_working_directory();
			puts(path);
		}
	}
	
	return 0;
}