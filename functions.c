#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <err.h>
#include <stdlib.h>
#include "env_lg.h"

extern char **environ;

/* Prints the current environment.  */
int list_current_envs()
{
    char **envs = environ;

    for (; *envs; envs++)
    {
        printf("%s\n", *envs);
    }
    return 0;
}

/* Sets environment variable.  */
int set_env(char *env_var)
{
    putenv(env_var);
    return 0;
}

/* Runs specified command/program */
int execute_command(char *command, char **arguments)
{
    execvp(command, arguments);
    int errcode = errno;
    err(errcode, "%s", command);
    return errcode;
}

/* Sets current environment to null */
void clear_environment() {
    char *empty_environment[] = { NULL };
    environ = empty_environment;
}
