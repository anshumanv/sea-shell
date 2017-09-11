#include <stdio.h>
#include <stdlib.h>
#include <ftw.h>
#include <dirent.h>
#include <string.h>

int removedir (const char* path)
{
   DIR *d = opendir(path);
   int ret=remove(path);
   
   if( ret != 0 )
    perror( "Error deleting file" );
   else
    puts( "Directory successfully deleted" );
   
   return 0;
}

int main(int argc, char *argv[3]){
    
    int d=removedir(argv[1]);
    return 0;
}
