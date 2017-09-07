// importing in-built libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <sys/types.h> 
#include <dirent.h> 
#include <ftw.h>
#include <sys/stat.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/ioctl.h> 

// importing self-made libs 
#include "pwd.c"
#include "ls.c"
#include "changeDirectory.c"
#include "rmdir.c"


int main() {
	char * cmd = (char *)malloc(100 * sizeof(char));
  cmd = "HOME";
  chdir(getenv(cmd));	//Changes directory to generic home path
  char * path = (char *)malloc(100 * sizeof(char));
  getcwd(path, 100); //Get the home directory and store it in path
	currdir = (char *)malloc(100*sizeof(char));
	strcpy(currdir, path);
	prevDir = (char *)malloc(100*sizeof(char));
	strcpy(prevDir, currdir);
	chdir(currdir);
	//Parent loop for our shell
	while(1) {
		int r = 0;
		printf("%s", "myshell$ > ");		// Printing shell name in each iteration
		
		// input command string
		char * ipcmd = (char *)malloc(100 * sizeof(char));
		
		// input command name and params
		char * cmdParams[2];
		cmdParams[0] = "";
		cmdParams[1] = "";
		fgets(ipcmd, 100, stdin);
		
		// remove trailing whitespaces
		ipcmd = strtok(ipcmd, "\n");

		int j;
		for( j = 0; j<strlen(ipcmd); j++){
			if (ipcmd[j] == ' '){
				r = 1;
			}
		}
		char *token = strtok(ipcmd, " ");
		
		// storing command name and params 
		int i;
		for(i = 0; i < r+1; i++){
			cmdParams[i] = strdup(token);
			token = strtok(NULL, " ");
		}
		
		// when input command is ls
		if (strcmp(cmdParams[0], "ls") == 0) {
			ls(currdir);
		}
		
		// when input command is cd
		else if (strcmp(cmdParams[0], "cd") == 0) {
			printf("%s\n", changeDir(cmdParams));
		}
		
		// when input command is mkdir
		else if (strcmp(cmdParams[0], "mkdir") == 0) {
			// code for mkdir
		}
		
		// when input command is rmdir
		else if (strcmp(cmdParams[0], "rmdir") == 0) {
			int d=remove_directory(cmdParams[1]);
    
    	if(d==0)
    		printf("Directory Successfully removed\n");
			else
				printf("Directory not found");

			
		}
		
		// when input command is pwd
		else if (strcmp(cmdParams[0], "pwd") == 0) {
			char *path = print_working_directory();
			puts(path);
		}
		
		r = 0;
		
	}
	
	return 0;
}
