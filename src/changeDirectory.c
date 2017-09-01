#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

//Global Variables
char * currdir = NULL;

//Funtion to concat two strings by efficiently allocating required memory.
char * concat(const char *s1, const char *s2) {
	char *result = malloc(strlen(s1) + strlen(s2) + 1);
	strcpy(result, s1);
	strcat(result, s2);
	return result;
}

char * changeDir(char * args[]){
	char * buff = (char *)malloc(100*sizeof(char));	//Buffer to send error message  if the directory doesn't exist.
	char * temp = (char *)malloc(100*sizeof(char));	//Temporarily stores value of current directory.
	strcpy(temp, currdir);
	temp = concat(temp, "/");
	temp = concat(temp, args[1]);
	//If directory doesn't exist, exit the function with error message
	if(chdir(temp) == -1){
		snprintf(buff, 100, "The directory %s doesn't exists", args[1]);
		return buff;
	}
	//If user just types 'cd', go to home directory
	if(args[1] == NULL){
		currdir = "/home/ubuntu";
		return currdir;
	}
	currdir = temp;	//If the given path is valid, update the currdir path.
	return currdir;
}

void main(){
	currdir = (char *)malloc(100*sizeof(char));
	currdir = "/home/ubuntu";
	char * args[] = {"cd", "Desktop"};
	printf("%s", changeDir(args));
}
