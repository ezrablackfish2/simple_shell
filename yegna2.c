#include "gasha.h"

/**
 * botaqeyary - this is what we biuld for a change directory
 * @info: the structural information inherited
 * Return: 1 for success and if you say ezra 0 for failure
 */

int botaqeyary(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
	{
		perror("getcwd failure");
		return (1);
	}
	if (!info->argv[1])
	{
		dir = akababiagni("HOME");
		if (!dir)
			chdir_ret = chdir((dir = akababiagni("PWD")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (qalatwididir(info->argv[1], "-") == 0)
	{
		if (!akababiagni("OLDPWD"))
		{
			atim(s);
			atim("\n");
			return (1);
		}
		atim(akababiagni("OLDPWD"));
		atim("\n");
		chdir_ret = chdir((dir = akababiagni("OLDPWD")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		chigiratami(info, "can't cd to ");
		write(2, info->argv[1], qalatrizmet(info->argv[1]));
		atim("\n");
	}
	else
		setenv("OLDPWD", akababiagni("PWD"), 1);
	return (0);
}
