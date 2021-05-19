#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "env_lg.h"

int main(int argc, char **argv)
{
    char *progname = argv[0];
    boolean has_command = argc > 1;
    int idx = 1;
    char *env_var;
    int opt;
    const char options[] = "h";

    while ((opt=getopt(argc, argv, options)) != -1)
    {
        idx++;
        /* Switch used to enable future flags to be added.  */
        switch (opt)
        {
            case 'h':
                usage(progname);
                return 0;
            /* case 'i':
                Todo: ignore current environment;
                break; */
            default:
                usage(progname);
                return 0;
        }
    }

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
    else if (has_command && idx > 1)
        return execute_command(argv[idx], &argv[idx + 1]);
    else
        usage(progname);
    return 0;
}

void usage(char *progname)
{
    printf("Usage: %s [NAME=VALUE...] [COMMAND [ARG...]]\n", progname);
    printf("Each NAME and VALUE pair is set to the environment then the COMMAND is run.\n");
}
