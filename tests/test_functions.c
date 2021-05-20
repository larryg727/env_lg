#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "minunit.h"
#include "../env_lg.h"

extern char *getenv(char *string);

int tests_run = 0;

static char *test_set_env()
{
    set_env("TEST=PASSING");
    char *env_var = getenv("TEST");
    mu_assert("Error; variable NOT added to environment", !strcmp(env_var, "PASSING"));
    return 0;
}

/* The execvp function in execute_command will take over process
    which does not allow tests to continue. */
// static char *test_execute_command()
// {
//     char *args_list[] = {"ls", "-l", NULL};
//     int exitcode = execute_command("ls", args_list);
//     mu_assert("Error: command not executed", exitcode == 0);
//     return 0;
// }

static char *all_tests()
{
    mu_run_test(test_set_env);
    // mu_run_test(test_execute_command);
    return 0;
}

int main(int argc, char **argv)
{
    char *result = all_tests();
    if (result != 0)
    {
        printf("%s\n", result);
    }
    else
    {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
