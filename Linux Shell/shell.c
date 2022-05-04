#include "shell.h"

int EOFVAR = 0; // Global variable used to determine if the eof character has been read (DON'T USE UNLESS EOF CHAR HAS BEEN READ FROM BATCHFILE!)

// used to exit the function
int myexit(char **args){
	return 0;
}

int main(int argc, char **argv){

	// ask for user prompt
	char choice[10] = "\0";
	char c;
	char *prompt = NULL;
	size_t bufsize = 30;
	signal(SIGINT, signalhandler);
	while(!strcmp(choice, "\0")){
	printf("Do you want to customize your prompt? (Type y for yes): ");
	scanf("%s", choice);
	c = getchar();
		if(!(strcmp(choice, "yes")) || !(strcmp(choice, "y"))){
			printf("Enter customized prompt: ");
			prompt = (char*) malloc(bufsize * sizeof(char));
			if(prompt == NULL){
				perror("Unable to allocate buffer");
				exit(1);
			}
			getline(&prompt, &bufsize, stdin);
			prompt[strlen(prompt)-1] = '\0';
		}
	}

	// set up batch mode if batchfile sent
	if(argc == 2)
	{	
		FILE *fp;
		fp = fopen(argv[1],"r");
		// go to input mode if file can't be found/opened, go to batch mode if file can be read
		if(fp==NULL){
			printf("File %s not found.\nEntering interactive mode...\n", argv[1]);
			if(prompt == NULL){
				prompt = (char*) malloc(bufsize * sizeof(char));
                        	if(prompt == NULL){
                                	perror("Unable to allocate buffer");
                                	exit(1);
                        	}
				strcpy(prompt, "prompt");
			}
			inputLoop(prompt, 1);		
		}
		else{
			dup2(fileno(fp), 0);
			fclose(fp);
			inputLoop(prompt, 0);
		}

	}
	// go to input mode if no batchfile specified
	else{
		printf("No batchfile included.\nEntering interactive mode...\n");
		if(prompt == NULL){
                	 prompt = (char*) malloc(bufsize * sizeof(char));
                         if(prompt == NULL){
                         	perror("Unable to allocate buffer");
                         	exit(1);
                         }
                         strcpy(prompt, "prompt");
               	}
                inputLoop(prompt, 1);
	}	
	return 0;
}

// loop for reading from batch loop, spliting arguments from line, and then executing arguments
void inputLoop(char *prompt, int intMode){

	int status;
	char* line;
	char** cmds;
	char** args;
	int commands = 1;
	int i;
	do{
		// print in input mode
		if(intMode)
			printf("%s: ", prompt);
		line = readLine(); // calls function to read lins from fd 0 - either stdin for input mode, or specified batchfile for batch mode
		// echo line from file in batch mode
		if(!intMode)		
			printf("%s\n",line);
		cmds = readCmds(line); // calls function to split up read in line into multiple commands seperated by ';', cmds[0] is a typecasted int for the number of commands in the line
		commands = (int) cmds[0]; 
		
		// for ever command read in, split the command into arguments and then execute them
		for(i=0; i < commands; i++){
			args = readArgs(cmds[i+1]); // splits each command into their arguments, seperated by whitespace
			status = execute(args); // passes the arguments to be executed, returns the status of the program (should be 1 if exit or fatal errors haven't occured)
			
			// adds alias commands -- current problems: can only hold up to 2 custom commands, otherwise would produce segmentation faults
			if (!strcmp(args[0], "alias"))
				addAlias(args);
			// adds comands to history -- current problems: invalid commands still show up in history, only stores one string from the line given, so only works for single string commands
			addHistory(args, line);
			
			if(args != NULL)
				free(args);
		}
		if(line != NULL)
			free(line);
		if(cmds != NULL)
			free(cmds);


	}  while (status && !EOFVAR); // loops so long as either status != 0, or EOFVAR == 1
	if(EOFVAR) // if the EOFVAR global variable is set, then the EOF character has been read in, and the batch file is empty
		printf("Warning, no exit call detected before EOF: terminating program.\n");
	return;
}

// reads in lines from batchfile
char *readLine(){
	// 512 characters is the current maximum command line size (defined in shell.h)
	int position = 0;
	char *line = malloc(sizeof(char) * MAXINPUTSIZE);
	char c;

	// loop for reading in characters from the batchfile
	while(1){

		c = getchar();
		if(c == EOF){
			EOFVAR = 1; // Set the EOFVAR to 1
			line[position] = '\0';
			return line;
			
		}else if(c == '\n'){
			line[position] = '\0';
			return line;
		}else {
			line[position] = c;
		}
		position++;
		
		if(position >= MAXINPUTSIZE){
			printf("Error, input excededs maxsize: %d.", MAXINPUTSIZE);
			exit(-1);
		}
	}
}

// splits line into commands
char **readCmds(char* line){
	char **cmds = malloc((MAXINPUTSIZE + 1) * sizeof(char*)); // MAX INPUT SIZE + 1 for the typecasted int returned at cmds[0]
	char *token;
	int commands = 0;

	token = strtok(line, ";"); // seperate line into strings seperated by the ';' character

	while(token != NULL){
		commands++;
		cmds[commands] = token;
		token = strtok(NULL, ";");
	}
	cmds[0] = (char*) commands; // typecast the number of commands to pass back inputLoop function
	
	return cmds;
}
// splits line into arguments
char **readArgs(char* line){ 
	char **args = malloc(MAXINPUTSIZE * sizeof(char*));
	char *token;
	int arguments = 0;

	token = strtok(line, " "); // finds arguments seperated by whitespace (spaces) in each command

	while(token != NULL){
		args[arguments] =  token;
		arguments++;
		token = strtok(NULL, " ");
	}
	args[arguments] = NULL; // append NULL to the end of args for every command
	return args;
}

// executes arguments
int execute(char** args){
	int i;
	bool exitFlag = false;

	// Individual built-in function calls
	if(!strcmp(args[0], "cd"))
		return mycd(args);
	else if(!strcmp(args[0], "exit")) 
		exitFlag=true;	//Original: return myexit(args);
	else if (!strcmp(args[0], "myhistory"))
		return myHistory(args);
	else if (!strcmp(args[0], "alias"))
		return alias(args);
		
	else if(!strcmp(args[0], "path"))
		return path(args);
	
	if(exitFlag==true) //If the line has "exit" the flag is triggered
		return myexit(args); //Executes exit last

	if(args[0] == NULL) // blank function call
                return 1;

	return launch(args); // launches non-modified programs
	
}

// launch for non-modified programs
int launch(char** args){
	pid_t pid;
	int status;

	pid = fork();
	// child function
	if (pid == 0){
		int i=0;
		int hasRedirection = 0;
		int hasPipeline = 0;

		// get the total terms for args 
		while(args[i] != NULL){
			i++;
		}

		// search backwards through arguments to find stream or pipe operators
		for(int j = i - 1; j > 0; j--){
			if((*args[j]) == '>' || (*args[j]) == '<'){
				if(!hasPipeline){
					hasRedirection = 1;
					args = redirection(args, j);
					continue;
				}
				else{
					fprintf(stderr, "%s", "Pipe and I/O redirection can't be handled\n");
					exit(-1);
				}
			}
			if((*args[j]) == '|'){
				if(!hasRedirection){
					hasPipeline = 1;
					// args = // assign args to new arguments from the function dealing with pipes
					continue;
				}
				else{
					fprintf(stderr, "%s", "Pipe and I/O redirection cant be handled\n");
					exit(-1);
				}
			}
		}

		if(execvp(args[0],args) == -1){ // call function and check if errror with function call
			perror("bad function call");
		}
	exit(-1); // terminate child
	}
	// error forking
	else if( pid < 0){
	perror("error forking");
	}
	// parent function
	else{	
		do{
			waitpid(pid, &status, WUNTRACED);
		}while(!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return 1;
}
