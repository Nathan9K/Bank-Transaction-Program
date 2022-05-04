#include "shell.h"

char** redirection(char** args, int i){
	FILE* ifp; // inputfilepointer
	FILE* ofp; // outputfilepointer

	if((*args[i]) == '<'){
		ifp = fopen(args[i+1], "r"); // open file to read to
		if(ifp == NULL){
			printf("File %s couldn't be opened: ", args[i+1]);
			args[0] = NULL; // set argument 0 to preform no operation
		}
		else{
			dup2(fileno(ifp), 0); // duplicate the file to stdin
			fclose(ifp);

			// loop to shift all arguments at i - NULL left 2 spots, to cover the < and file arguments
			args[i] = args[i+2];
			args[i+1] = args[i+3];
			while(args[i+3] != NULL){
				i=i+2;
				args[i] = args[i+2];
				args[i+1] = args[i+3];
			}
				
			return args; // return shifted arguments
		}
	}
	else if((*args[i]) == '>'){
		ofp = fopen(args[i+1], "w"); // open file to write to
		if(ofp == NULL){
			printf("File %s couldn't be opened: ", args[i+1]);
			args[0] = NULL; // set argument 0 to NULL to preform no operation
		}
		else{
			dup2(fileno(ofp), 1); // duplicate the file to stdout
			fclose(ofp);	
			
			// loop to shift all arguments at i - NULL left 2 spots, to cover the > and file arguments
			args[i] = args[i+2];
			args[i+1] = args[i+3];
			while(args[i+3] != NULL){
				i=i+2;
				args[i] = args[i+2];
				args[i+1] = args[i+3];
			}

			return args; // return shifted arguments
		}
	}

	return args;
}
