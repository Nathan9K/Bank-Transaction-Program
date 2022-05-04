
#include "shell.h"

// history array and history index
char* history[20];
unsigned history_count = 0;

int myHistory(char** args)
{
	// if user enters 'myhistory -c' into the prompt, clear history
	if (args[1] != NULL && (!strcmp(args[1], "-c")))
	{
		memset(history, 0, sizeof(history));
		history_count = 0;
		printf("history cleared\n");
		return 1;
	}

	if (args[1] != NULL && (!strcmp(args[1], "-e")))
	{
		int historyNum;

		// if user enters 'myhistory -e' without giving integer specified for history 
		if (args[2] == NULL)
		{
			printf("not found, enter input followed by -e\n");
		}
		// if user enters a value after 'myhistory -e'
		else if (args[2] != NULL)
		{
			historyNum = atoi(args[2]);

			// if args[2] = valid history index -- execute command
			for (int i = 1; i < 21; i++)
			{
				if (i == historyNum)
				{
					system(history[historyNum - 1]);
					return 1;
				}
				else
				{
					continue;
				}
			}
			printf("command not found in history\n");
			return 1;
		}
	}

	int i = 0;
	while (history[i] != NULL)
	{
		printf("%d: %s\n", i + 1, history[i]);
		i = i + 1;
	}

	return 1;
}


// function called in inputLoop -- adds the commands to history
void addHistory(char** args, char* line)
{
	if ( (history_count < 20) )
	{
		history[history_count++] = strdup(args[0]);
	}
	else
	{
		free(history[0]);

		for (unsigned i = 1; i < 20; i++)
		{
			history[i - 1] = history[i];
		}

		history[20 - 1] = strdup(args[0]);
	}
}

