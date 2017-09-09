void makedir(char* argv) { 	
	const int dir_err = mkdir(argv ,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);	
  if (-1 == dir_err) {
			perror("Error creating directory!\n");
    	    
	} else {
	        printf("File created successfully!\n");	
	}
     
}
