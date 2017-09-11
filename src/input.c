/*This function returns the number of space seperated words in a given string
Just pass the base string and an array pointer 
Use the number of words which will be returned by the function : int n
Run loop till n to print all words */
int getWords(char *base, char target[10][20])
{
	int n=0,i,j=0;
	
	for(i=0;TRUE;i++)
	{
		if(base[i]!=' '){
			target[n][j++]=base[i];
		}
		else{
			target[n][j++]='\0';//insert NULL
			n++;
			j=0;
		}
		if(base[i]=='\0')
		    break;
	}
	return n;
	
}

