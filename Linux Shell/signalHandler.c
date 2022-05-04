#include "shell.h"

void signalHandler()
{
		int pid;
		int newpro = fork();
		if(newpro == 0)
			kill(newpro, SIGKILL);
		
}
