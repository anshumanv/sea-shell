//Global Variables
char * currdir = NULL;
char * prevDir = NULL;


//Function to store previously opened path
char * storePreviousDirectory(char * dir){
	char * previous = (char * )malloc(100*sizeof(char));
	strcpy(previous, dir);
	return previous;
}


//Funtion to concat two strings by efficiently allocating required memory.
char * concat(const char *s1, const char *s2) {
	char *result = malloc(strlen(s1) + strlen(s2) + 1);
	strcpy(result, s1);
	strcat(result, s2);
	return result;
}

//Changes the directory
char * changeDir(char * args[]){
	char * buff = (char *)malloc(100*sizeof(char));	//Buffer to send error message  if the directory doesn't exist.
	char * temp = (char *)malloc(100*sizeof(char));	//Temporarily stores value of current directory.
	strcpy(temp, currdir);
	temp = concat(temp, "/");
	temp = concat(temp, args[1]);
	//If directory doesn't exist, exit the function with error message
	if(chdir(temp) == -1 && strcmp(args[1], "-")!=0){
		snprintf(buff, 100, "The directory %s doesn't exists", args[1]);
		return buff;
	}
	
	//If directory  exist, get to the this directory
	if(chdir(temp) == 0){
	currdir=temp;
	return currdir;
	}  

	
	//If '-' return previous directory
	if(strcmp(args[1], "-")==0){
		chdir(prevDir);
		currdir = prevDir;
		return prevDir;
	}else{
		prevDir = storePreviousDirectory(currdir);
	}
	
	
	//If user types (cd ..) then return to the previous directory
	if(strcmp(args[1],"..")==0){
		int l=strlen(currdir); 
		int i;
		for(i=l-1;currdir[i]!='/';i--){
			currdir[i]='\0';
		} 
		currdir[i]='\0';  
		return currdir;                         
	}

	
	//If user just types 'cd', go to home directory
	if(args[1] == ""){
		chdir(getenv("HOME"));
		getcwd(currdir, 100);
		return currdir;
	}
	
	currdir = temp;	//If the given path is valid, update the currdir path.
	return currdir;
}

