// importing in-built libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>      /* struct stat */
#include <sys/types.h>     /* S_IFMT */
#include <dirent.h>
#include <time.h>          /* strftime, ctime */
#include <pwd.h>           /* struc passwd (to retrieve user name) */
#include <grp.h>           /* struc group (to retrieve group name) */ 
#include <ftw.h>
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/ioctl.h> 

// importing self-made libs 
#include "pwd.c"
#include "ls.c"
#include "changeDirectory.c"
#include "rmdir.c"
#include "mkdir.c"
#include "lsdetailed.c"

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
		printf("%s @ %s", currdir, "myshell$ > ");		// Printing shell name in each iteration
		
		// input command string
		char * ipcmd = (char *)malloc(100 * sizeof(char));
		
		// input command name and params
		char * cmdParams[3];
		cmdParams[0] = "";
		cmdParams[1] = "";
		cmdParams[2] = "";
		fgets(ipcmd, 100, stdin);
		
		// remove trailing whitespaces
		ipcmd = strtok(ipcmd, "\n");

		int j;
		for( j = 0; j<strlen(ipcmd); j++){
			if (ipcmd[j] == ' '){
				r++;
			}
		}
		char *token = strtok(ipcmd, " ");
		
		// storing command name and params 
		int i;
		for(i = 0; i < r+1; i++){
			cmdParams[i] = strdup(token);
			token = strtok(NULL, " ");
		}
		
		/*for(i = 0; i<3; i++)
			printf("%s", cmdParams[i]);*/
		
		// when input command is ls
		if (strcmp(cmdParams[0], "ls") == 0) {
			if(strcmp(cmdParams[1], "-l") == 0){
				lsdetailed(currdir, 0);
			}
			else if(strcmp(cmdParams[1], "-a") == 0){
				lsdetailed(currdir, 1);
			}
			else ls(currdir);
		}
		
		// when input command is cd
		else if (strcmp(cmdParams[0], "cd") == 0) {
			changeDir(cmdParams);
		}
		
		// when input command is mkdir
		else if (strcmp(cmdParams[0], "mkdir") == 0) {
	 		makedir(cmdParams);
		}
		
		// when input command is rmdir
		else if (strcmp(cmdParams[0], "rmdir") == 0) {
			remove_directory(cmdParams);
		}
		
		// when input command is pwd
		else if (strcmp(cmdParams[0], "pwd") == 0) {
			printf("%s\n", currdir);
		}
		
		else if (strcmp(cmdParams[0], "exit") == 0) {
			return 0;
		}
		
		else printf("%s", "Invalid Command !\n");
		
		r = 0;
		
	}
	
	return 0;
}
