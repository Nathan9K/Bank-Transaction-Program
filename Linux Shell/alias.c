
#include "shell.h"

char* aliasLine[20];
char* userCmds[20];
char* cmdCall[20];
unsigned alias_count = 0;

// function to obtain substrings from the alias lines that the user enters 
char* substr(const char *src, int m, int n){
    int len = n - m;
    char *dest = (char*)malloc(sizeof(char) * (len + 1));
    for (int i = m; i < n && (*(src + i) != '\0'); i++)
    {
        *dest = *(src + i);
        dest++;
    }
    *dest = '\0';
    return dest - len;
}

// displays alias custom commands and executes alias commands
// can only hold up to 2 custom commands due to segmentation fault errors -- issue with substrings after 2 
int alias(char** args)
{	
	int i = 0;
	
	if ( (aliasLine[i] != NULL) && (args[1] == NULL) )
	{
		printf("alias functionality can hold up to 2 custom commands\n");
		printf("user may assign commands to a single character\n");
		printf("example: alias c='clear'\n\n");

		printf("current user commands:\n");
	}
	
	// if only 'alias' is entered into the prompt while alias commands are not NULL 
	while ( (aliasLine[i] != NULL) && (args[1] == NULL) && (i < 2) )
	{
		printf("%s\n", aliasLine[i]);
		//printf("custom command is %s\n", userCmds[i]);
		//printf("actual command is %s\n", cmdCall[i]);
		i++;		
	}
	
	// if only 'alias' is entered but no alias commands exist
	if (aliasLine[0] == NULL && args[1] == NULL)
	{
		printf("[WARNING] alias commands empty\nplease type 'alias' followed by a single character for the command\n");
		printf("example: alias c='clear'\n");
	}
	
	// if 'alias' is entered followed by another string -- executes command given by user if it exists
	for (int i = 0; i < 2; i++)
	{
		if ( (aliasLine[i] != NULL) )
		{
			if ((args[1] != NULL) && (strcmp(substr(args[1], 1, 2), "=")))
			{
			
				if (!strcmp(args[1], userCmds[i]))
				{
					system(cmdCall[i]);
					return 1;
				}	

			}	
		}
	}
	
	// check if the command was not found -- produce error message


	return 1;
}

// adds alias commands to an array similar to the history function
void addAlias(char** args)
{
	if (args[1] != NULL && ((!strcmp(substr(args[1], 1, 2), "="))))
	{
		if (alias_count < 20)
		{
			aliasLine[alias_count++] = strdup(args[1]);
		}
		else
		{
			free(aliasLine[0]);

			for (unsigned i = 1; i < 20; i++)
			{
				aliasLine[i - 1] = aliasLine[i];
			}

			aliasLine[20 - 1] = strdup(args[1]);
		}
	}
	
	
	// creates substrings of the user's custom command and the actual command
	for (int i = 0; i < 2; i++)
	{
		if (aliasLine[i] != NULL)
		{
			if ( (!strcmp(substr(aliasLine[i], 1, 2), "=")) )
			{
				// store user input for given command
				userCmds[i] = substr(aliasLine[i], 0, 1);
				// store actual command associated with user input
				cmdCall[i] = substr(aliasLine[i], 3, strlen(aliasLine[i])-1);
			}			
		}
	}
}

