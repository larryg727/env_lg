#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "env_lg.h"

int main(int argc, char **argv)
{
    boolean has_command = argc > 1;
    int idx = 1;
    char *env_var;

    while (idx < argc && (env_var = strchr(argv[idx], '=')))
    {
        if (strchr(argv[idx], '='))
        {
            set_env(argv[idx]);
            idx++;
        }
    }
    if (!has_command || !argv[idx])
        return list_current_envs();
    else
    {
        return execvp(argv[idx], &argv[idx + 1]);
    }
}
