#include "gasha.h"

/**
 * siraagigni - is the finding funciton for our built in funciton
 * @info: is the structural inheritance
 * Return: yes 1 -2 great error and 0 faliure
 */

int siraagigni(info_t *info)
{
	int i, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", mewicha},
		{"env", akababy},
		{"cd", botaqeyary},
		{"setenv", argakababy},
		{"unsetenv", akababyatfa},
		{"alias", akababyatfa},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
	{
		if (qalatwididir(info->argv[0], builtintbl[i].type) == 0)
		{
			built_in_ret = builtintbl[i].func(info);
			break;
		}
	}

	return (built_in_ret);
}
