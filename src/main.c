#include <stdio.h>
#include <string.h>
#include "pwd.c"

int main() {
	
	//Parent loop for our shell
	while(1) {
		printf("%s", "myshell$ > ");		// Printing shell name in each iteration
		char ipcmd[100];								// Input command string
		gets(ipcmd);										// Reading input command string
		
		// when input command is ls
		if (strcmp(ipcmd, "ls") == 0) {
			// code for ls
		}
		
		// when input command is cd
		else if (strcmp(ipcmd, "cd") == 0) {
			// code for cd
		}
		
		// when input command is mkdir
		else if (strcmp(ipcmd, "mkdir") == 0) {
			// code for mkdir
		}
		
		// when input command is rmdir
		else if (strcmp(ipcmd, "rmdir") == 0) {
			// when code is rmdir
		}
		
		// when input command is pwd
		else if (strcmp(ipcmd, "pwd") == 0) {
			char *path = print_working_directory();
			puts(path);
		}
		
		
	}
	
	return 0;
}
