#include <stdio.h>
#include <string.h>
#include "pwd.c"

//Global Variables
char * currdir = NULL;
char * prevDir = NULL;


int main() {
	
	//Parent loop for our shell
	while(1) {
		
		printf("%s", "myshell$ > ");		// Printing shell name in each iteration
		
		// input command string
		char * ipcmd = (char *)malloc(100 * sizeof(char));
		
		// input command name and params
		char * cmdParams[2];
		fgets(ipcmd, 100, stdin);
		
		// remove trailing whitespaces
		ipcmd = strtok(ipcmd, "\n");
		char *token = strtok(ipcmd, " ");
		
		// storing command name and params 
		for(int i = 0; i < 2; i++){
			cmdParams[i] = strdup(token);
		
			if(strtok(NULL, " ") == NULL){break;}
				token = strtok(NULL, " ");
		}
		
		// when input command is ls
		if (strcmp(cmdParams[0], "ls") == 0) {
			// code for ls
		}
		
		// when input command is cd
		else if (strcmp(cmdParams[0], "cd") == 0) {
			// code for cd
		}
		
		// when input command is mkdir
		else if (strcmp(cmdParams[0], "mkdir") == 0) {
			// code for mkdir
		}
		
		// when input command is rmdir
		else if (strcmp(cmdParams[0], "rmdir") == 0) {
			// when code is rmdir
		}
		
		// when input command is pwd
		else if (strcmp(cmdParams[0], "pwd") == 0) {
			char *path = print_working_directory();
			puts(path);
		}
		
		
	}
	
	return 0;
}
