#include <stdio.h>
#include <unistd.h>
#include "env_lg.h"

extern int putenv(char *string);

/* Prints the current environment.  */
int list_current_envs()
{
    extern char **environ;
    char **envs = environ;

    for (; *envs; envs++)
        printf("%s\n", *envs);
    return 0;
}

/* Sets environment variable.  */
int set_env(char* env_var)
{
    putenv(env_var);
    return 0;
}
