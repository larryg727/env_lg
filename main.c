#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "env_lg.h"

void usage(char *progname);

int main(int argc, char **argv)
{
    char *progname = argv[0];
    boolean has_command = argc > 1;
    int idx = 1;     /* Tracks index of arguments that are processed */
    char *env_var;   /* Temp variable to hold passed in env varialbs as they are found */
    int opt;         /* Temp variable to hold passed in option flags as they are found */
    const char options[] = "h"; /* List of accepted option flags */

    /*  parse option flags */
    while ((opt=getopt(argc, argv, options)) != -1)
    {
        idx++;
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

    /* parse environment variables */
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
