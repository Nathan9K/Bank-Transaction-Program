/*#include "shell.h"
//Still some kinks I need to work out
char parse(char *line)
{
    char **cmds = malloc((MAXINPUTSIZE + 1) * sizeof(char *)); // MAX INPUT SIZE + 1 for the typecasted int returned at cmds[0]
    char *token;
    int commands = 0;

    token = strtok(line, "|"); // seperate line into strings seperated by the ';' character

    while (token != NULL)
    {
        commands++;
        cmds[commands] = token;
        token = strtok(NULL, "|");
    }
    cmds[0] = (char *)commands; // typecast the number of commands to pass back inputLoop function

    return cmds;
}

void pipe(char **args, int j)
{
    int fd1[2];
    int fd2[2];
    //First child
    if (fork() == 0)
    {
        close(fd1[0]);
        dup2(fd1[0], 1);
        close(fd1[1]);

        parse(args);
        execlp(args, NULL);
    }
    //Second child
    if (fork() == 0)
    {
        close(fd1[0]);
        dup2(fd1[0], 1);
        close(fd1[1]);

        close(fd2[0]);
        dup2(fd2[0], 1);
        close(fd2[1]);

        parse(args);
        execlp(args, NULL);
    }
    close(fd1[0]);
    close(fd1[1]);
    close(fd2[0]);
    close(fd2[1]);

    wait(NULL);
}*/
