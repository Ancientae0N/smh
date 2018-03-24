
%{
	#include <stdio.h>
	#include <stdlib.h>
	void yyerror(const char*);
	int yywrap(void);
	int yylex(void);
%}
%token  NOTOKEN, GREAT, NEWLINE, WORD, GREATGREAT, PIPE, AMPERSAND, GREATAMPERSAND, GREATGREATAMPERSAND, LESS
%%
goal: command_list
    ;
arg_list: arg_list WORD
	| /*empty*/
	;
cmd_and_args:	WORD arg_list
	    ;

pipe_list: pipe_list PIPE cmd_and_args
	 | cmd_and_args
	 ;
io_modifier: GREATGREAT WORD
	   | GREAT WORD
	   | GREATGREATAMPERSAND WORD
	   | GREATAMPERSAND WORD
	   | LESS WORD
	   ;
io_modifier_list: io_modifier_list io_modifier
	        | /*empty*/
	        ;
background_optional: AMPERSAND
		   | /*empty*/
		   ;
command_line: pipe_list io_modifier_list background_optional NEWLINE
	    | NEWLINE /*accept empty cmd line*/
	    | error NEWLINE{yyerrok;}
	    ;
/*error recovery*/
command_list :	command_list command_line
	     |
	     ;/* command loop*/
%%
void yyerror(const char* s){
	printf("%s\n", s);
	exit(0);
}
