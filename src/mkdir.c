void makedir(char* argv[]) { 	
	if(strcmp(argv[1],"-v")==0){	
		const int dir_err = mkdir(argv[2] ,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);	
   		if (-1 == dir_err) {
			perror("Error creating directory!\n");
    	    } 
		else {
		        printf("File directory %s successfully!\n",argv[2]);	
			}
    } 
	
	if(strcmp(argv[1],"-p")==0){	
		const int dir_err = mkdir(argv[2] ,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);	
   		if (-1 == dir_err) {
			perror("Error creating directory!\n");
    	    } 
    } 
	
	else{	
			const int dir_err = mkdir(argv[1] ,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);	
   			if (-1 == dir_err) {
			perror("Error creating directory!\n");
    	    } 
    } 
}
