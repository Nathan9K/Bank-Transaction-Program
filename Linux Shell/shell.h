#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#ifndef MAXINPUTSIZE
#define MAXINPUTSIZE 512 // Defines the maximum size of a line input as 512 characters
#endif

// Shell functions
void inputLoop(char* prompt, int intMode);
char *readLine();
char **readCmds(char* line);
char **readArgs(char* line);
int execute(char** args);
int launch(char** args);

// Individual functions
int myexit(char** args);
int mycd(char** args);
void addHistory(char** args, char* line);
int myHistory(char** args);
void addAlias(char** args);
int alias(char** args);
int path(char** args);
void signalHandler();

char **redirection(char** args, int i);
