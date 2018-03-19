#include "tokenizer.h"

commands split (char input[SIZE])
{
	commands temp;
	int i = 0;
	int curr = 0;
//	char result[SIZE][SIZE];
	char buf[SIZE];
	memset(buf,0,strlen(buf));
	int cur_buf = 0;
	while(i <= strlen(input))
	{
		if (input[i] == ' ' || input[i] == '\0')
		{
			strcpy(temp.result[curr++], buf);
			memset(buf,0,strlen(buf));
			cur_buf = 0;
		}
		else
		{
			buf[cur_buf++] = input[i];
		}
		i++;
	}

//	temp.result = result;
	temp.length = curr;
	return temp;
}


int main () {
   char str[SIZE] = "ls -l ps > a.out";
   const char s[2] = " ";
/*
   char *token;
   
   /* get the first token 
   token = strtok(str, s);
   
   /* walk through other tokens 
   while( token != NULL ) {
      printf( " %s\n", token );
    
      token = strtok(NULL, s);
   }
*/   
   commands list = split(str);
   int i;
   for(i = 0; i < list.length; i++)
   {
   	printf("%s\n", list.result[i]);
   }
   return(0);
}
