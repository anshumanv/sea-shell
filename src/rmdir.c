int remove_directory(const char *path){   // "path"- parameter passing for directory to be removed
   DIR *d = opendir(path);  // Move to the desired path to remove directory
   size_t path_len = strlen(path);  // length of path
   int r = -1;  // Status variable 
   if (d){    // if the path exists
      struct dirent *p;
      r = 0;   // Status variable
      while (!r && (p=readdir(d))){    //  execute the loop until the directory isn't empty 
          int r2 = -1;  
          char *buf; // storing and updating the current path in this variable
          size_t len;


          if (!strcmp(p->d_name, ".") || !strcmp(p->d_name, "..")){   // Check for "." & ".." files ; if found, continue
             continue;  // don't remove the above files
          }
          len = path_len + strlen(p->d_name) + 2;  //  
          buf = malloc(len);  // Allocate memory at runtime
          if (buf){          // If block statement for checking and deleting file/directory
             struct stat statbuf;
             snprintf(buf, len, "%s/%s", path, p->d_name);
             if (!stat(buf, &statbuf)){
                if (S_ISDIR(statbuf.st_mode)){    // Check for directory
                   r2 = remove_directory(buf);    // remove directory
                }
                else{
                   r2 = unlink(buf);    // unlink command for deleting files
                }
             }
             free(buf);     // Free the allocated memory so as it can be used the next time the rmdir command is executed
          }
          r = r2;  // updating the status variable
      }
      closedir(d);  //trace back to the original path
   }

   if (!r){
      r = rmdir(path);    // if r!=0 or the outermost directory hasn't been deleted, remove it  
   }
	return r;   // return the function status to main

}
