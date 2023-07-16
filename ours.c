#include "terminal.h"

int ourexit(info_t *info) 
{
    free_info(info, 0);
    return 0;
}

int ourenv(info_t *info) {
	char** env;
	char *env_entry;
	int i;


	i = info->argc;	
	i++;
	env = get_environ();
    if (env != NULL) {
        while (*env != NULL) {
            env_entry = *env;
            _print(env_entry);
            _print("\n");
            env++;
        }
    }
    return 0;
}

int oursetenv(info_t *info) {
    if (info->argv[1] != NULL && info->argv[2] != NULL) {
        if (setenv(info->argv[1], info->argv[2], 1) == 0) {
            _print("Environment variable set successfully.\n");
            return 0;
        } else {
            print_error(info, "Failed to set environment variable.");
            return 1;
        }
    } else {
        print_error(info, "Invalid number of arguments.");
        return 1;
    }
}

int ourunsetenv(info_t *info) {
    if (info->argv[1] != NULL) {
        if (unsetenv(info->argv[1]) == 0) {
            _print("Environment variable unset successfully.\n");
            return 0;
        } else {
            print_error(info, "Failed to unset environment variable.");
            return 1;
        }
    } else {
        print_error(info, "Invalid number of arguments.");
        return 1;
    }
}

alias_entry alias_table[MAX_ALIASES];
int num_aliases;

int ouralias(info_t *info) 
{
	int i;

	num_aliases = 0;
    if (info->argc < 3) 
    {
        _print("Usage: alias <alias_name> <command>\n");
        return 1;
    }

    if (num_aliases >= MAX_ALIASES) {
        _print("Maximum number of aliases reached.\n");
        return 1;
    }

    for (i = 0; i < num_aliases; i++) {
        if (_strcmp(info->argv[1], alias_table[i].alias) == 0) {
            _strcpy(alias_table[i].command, info->argv[2]);
            return 0;
        }
    }

    _strcpy(alias_table[num_aliases].alias, info->argv[1]);
    _strcpy(alias_table[num_aliases].command, info->argv[2]);
    num_aliases++;

    return 0;
}


int ourcd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
	{
		perror("getcwd failure");
		return 1;
	}

	if (!info->argv[1])
	{
		dir = envget("HOME");
		if (!dir)
		{
			chdir_ret = chdir((dir = envget("PWD")) ? dir : "/");
		}
		else
		{
			chdir_ret = chdir(dir);
		}
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!envget("OLDPWD"))
		{
			_print(s);
			_print("\n");
			return 1;
		}
		_print(envget("OLDPWD"));
		_print("\n");
		chdir_ret = chdir((dir = envget("OLDPWD")) ? dir : "/");
	}
	else
	{
		chdir_ret = chdir(info->argv[1]);
	}

	if (chdir_ret == -1)
	{
		perror("cd failed");
	}
	else
	{
		setenv("OLDPWD", envget("PWD"), 1);
	}
	return 0;
}
