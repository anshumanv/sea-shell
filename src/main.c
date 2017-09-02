#include<stdio.h>

int main(){
	
	//Parent loop for our shell
	while(1) {
		printf("%s", "myshell$ > ");		// Printing shell name in each iteration
		char ipcmd[100];					// Input command string
		gets(ipcmd);						// Reading input command string
	}
	
return 0;
}
