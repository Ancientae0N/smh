/*
* shell.l: simple lexical analyzer for the shell.
*/
%{
#include <string.h>
#include <stdio.h>
#include "y.tab.h"
#include <stdlib.h>
	int yywrap(void);
	int yylex(void);
%}
%%
\n {return NEWLINE;}

[ \t] {
/* Discard spaces and tabs */
}
">" {return GREAT;}

"<" {return LESS;}

">>" {return GREATGREAT;}

">&" {return GREATAMPERSAND;}
">>&" {return GREATGREATAMPERSAND;}

\|	{return PIPE;}

\& {return AMPERSAND;}

[a-zA-Z_-][a-zA-Z_0-9]*	 {return WORD;}

.		  {return NOTOKEN;}
%%
int main()
{
	printf("Enter Input: ");
	if(!yyparse())
		printf("Valid command line argument\n");
	else
		printf("Invalid argument\n");
	return 0;
}
