#include "gasha.h"

/**
 * mewicha - this is our custom made exit funciton
 * @info: the strucutual inheritance property
 * Return: always 0 succesful exit
 */

int mewicha(info_t *info)
{
	int i;

	if (info->arg != NULL)
	{
		free(info->arg);
		info->arg = NULL;
	}
	if (info->argv != NULL)
	{
	for (i = 0; info->argv[i]; i++)
		free(info->argv[i]);
	free(info->argv);
	info->argv = NULL;
	}
	antshi(info, 0);
	return (0);
}

/**
 * akababy - ezra and aman's custom made environemnt
 * @info: the structural inhertiance again for property
 * Return: 1 success and 0 for failure
 */

int akababy(info_t *info)
{
	char **env;
	char *env_entry;
	int i;


	i = info->argc;
	i++;
	env = inagignakababi();
	if (env != NULL)
	{
		while (*env != NULL)
		{
			env_entry = *env;
			atim(env_entry);
			atim("\n");
			env++;
		}
	}
	return (0);
}

/**
 * argakababy - we need a custom made but using the old timessake setenv
 * @info: the structural inheritiance
 * Return: 1 right 0 wrong
 */

int argakababy(info_t *info)
{
	if (info->argv[1] != NULL && info->argv[2] != NULL)
	{
		if (setenv(info->argv[1], info->argv[2], 1) == 0)
		{
			atim("Environment variable set successfully.by ezra and aman every one\n");
			return (0);
		}
		else
		{
			chigiratami(info, "Failed to set environment variable.by ezra and aman wh");
			return (1);
		}
	}
	else
	{
		chigiratami(info, "Invalid number of arguments. the signature ofezra and");
		return (1);
	}
}

/**
 * akababyatfa - this is ezra and aman unseting env custom made but use
 * @info: structural inheritance of the property
 * Return: 1 great 0 failure
 */

int akababyatfa(info_t *info)
{
	if (info->argv[1] != NULL)
	{
		if (unsetenv(info->argv[1]) == 0)
		{
			atim("Environment variable unsetby ezra and aman the alx workers tough\n");
			return (0);
		}
		else
		{
			chigiratami(info, "Failed to unset againby ezra and aman wow everyone how");
			return (1);
		}
	}
	else
	{
		chigiratami(info, "Invalid number of arguments ezra and aman the god heros");
		return (1);
	}
}

/**
 * teteki - this is ezra aman alias but the probelm is still not working
 * @info: our inheritance structural
 * Return: 1 yes 0 no
 */

int teteki(info_t *info)
{
	alias_entry alias_table[100];
	int num_aliases;
	int i;

	num_aliases = 0;
	if (info->argc < 3)
	{
		atim("alias ezra and aman we are sorry everyone we not finish this sorry\n");
		return (1);
	}
	if (num_aliases >= MAX_ALIASES)
	{
		atim("Maximum number of aliases reached. said ezra the hero the god aman\n");
		return (1);
	}
	for (i = 0; i < num_aliases; i++)
	{
		if (qalatwididir(info->argv[1], alias_table[i].alias) == 0)
		{
			qalatqegni(alias_table[i].command, info->argv[2]);
			return (0);
		}
	}
	qalatqegni(alias_table[num_aliases].alias, info->argv[1]);
	qalatqegni(alias_table[num_aliases].command, info->argv[2]);
	num_aliases++;
	return (0);
}

