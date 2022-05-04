#include "shell.h"

// Used to change directory to the args[1] directory, if no arguments are passed, change to user's home directory
int mycd(char **args){
	if(args[1] == NULL){
		char* homedir = getenv("HOME");
		if(chdir(homedir) != 0){
			perror("can't cd");
		}
	}
	else{
		if(chdir(args[1]) != 0){
			perror("can't cd");
		}	
	}
	return 1;
}

