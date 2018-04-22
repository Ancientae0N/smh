
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
void getTokens(char cmd[], char* arg[]){
	char inp[1024]; // character input
	int count = 0, i = 0, j = 0;
	char *tokens[100] = {NULL};
	char *token;
	//read characters
	for(;;){
		char c = fgetc(stdin);
		inp[count++] = c;
		if(c == '\n') break;
	}
	if(count == 1) return;
	token = strtok(inp, " \n");
	while(token!=NULL){
		tokens[i++] = strdup(token);
		token = strtok(NULL, " \n");}
	
	//first word is always the command, so store that as the cmd
	strcpy(cmd, tokens[0]);
	for(j = 0; j<i; j++)
		arg[j] = tokens[j];
	arg[i] = NULL;
}


int main(){
	char cmd[100], command[100], *arg[20];
	char *envp[] = {"PATH =/bin", 0};
	while(1){
		printf("Shelltest@Vishal^ ");
		//if(arg[1] != '\0')
			//arg[1] = '\0';
		getTokens(command, arg);
		printf("%s %s\n", arg[0],arg[1]);

		if((fork()) != 0){ //parent
			wait(NULL);
		}
		else{
			strcpy(cmd, "/bin/");
			strcat(cmd, command);
			execve(cmd, arg, envp);
			
		}
		if(strcmp(command, "exit") == 0){
			break;}
	}
}
