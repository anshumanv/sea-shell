
#include <sys/stat.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){ 
	if(strcmp(argv[1],"-v")==0){
		const int dir_err = mkdir(argv[2] ,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
		printf("created directory '%s' \n",argv[2]);	
		if (-1 == dir_err){
			printf("Error creating directory!\n");
    		exit(1);
		}	
	}
	else if(strcmp(argv[1],"-p")==0){
    	const int dir_err = mkdir(argv[2] ,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);	
		if (-1 == dir_err){
			printf("Error creating directory!\n");
    		exit(1);
		}	
	}	
	else{
		const int dir_err = mkdir(argv[1] ,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);	
		if (-1 == dir_err){
			printf("Error creating directory!\n");
    		exit(1);
		}
	}	
	
	return 0;
}
