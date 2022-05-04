#include "shell.h"

char* origpath = getenv("PATH");

int path(char** args)
{
	char* pathvar = getenv("PATH");
    char *currentPath = getenv("PATH")
    if(args[1] == NULL)
	{ // display current path names
		printf("%s \n", pathvar);
		return 1;
	}
	else if(!strcmp(args[1], "+")
	{ // add path to pathvar
		strcat(pathvar, args[2]);
		return 1;
	}
	else if(!strcmp(args[1], "-")
	{ // remove path from pathvar
		size_t length = strlen(args[2]);
        char *p = pathvar;
        while ((p = strstr(p, args[2])) != NULL) 
		{
                memmove(p, p + length, strlen(p + length) + 1);
        }
        pathvar = p;
        return 1;
	}
	setenv(pathvar, currentPath, 1);
	return 0;
}
