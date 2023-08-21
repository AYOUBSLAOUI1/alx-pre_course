#include "simple_shell.h"

int simple_executing(char *con, char **array)
{
        int exit = 0;
        int stat;
        pid_t pid = fork();

        if (pid == -1)
        {
                perror("ERROR");
                exit(1);
        }

        if (pid == 0)
        {
                execve(con, array, NULL);
                perror(array[0]);
                exit(errno);
        } else
        {
                wait(&stat);
                exit = WEXITSTATUS(stat);
        }

        (return exit);
}
