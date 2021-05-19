
typedef enum { False, True } boolean;

int list_current_envs(void);
int set_env(char env_var[]);
int execute_command(char *command, char **arguments);
