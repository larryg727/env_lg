#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "env_lg.h"

extern char *__progname;

void usage(char *progname);

int main(int argc, char **argv)
{
    // char *progname = argv[0];
    int idx = 1;                 /* Tracks index of arguments that are processed */
    char *env_var;               /* Temp variable to hold passed in env varialbs as they are found */
    int opt;                     /* Temp variable to hold passed in option flags as they are found */
    const char options[] = "hi"; /* List of accepted option flags */

    /*  parse option flags */
    while ((opt = getopt(argc, argv, options)) != -1)
    {
        idx++;
        switch (opt)
        {
        case 'h':
            usage(__progname);
            return 0;
        case 'i':
            clear_environment();
            break;
        default:
            usage(__progname);
            return 0;
        }
    }

    /* parse environment variables */
    while (idx < argc && (env_var = strchr(argv[idx], '=')))
    {
        set_env(argv[idx]);
        idx++;
    }

    if (argv[idx])
    {
        return execute_command(argv[idx], &argv[idx]);
    }
    else
    {
        return list_current_envs();
    }
    return 0;
}

void usage(char *progname)
{
    printf("Usage: %s [NAME=VALUE...] [COMMAND [ARG...]]\n"
           "Each NAME and VALUE pair is set to the environment then the COMMAND is run.\n",
           progname);
}
