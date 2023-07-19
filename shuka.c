#include "gasha.h"

/**
 * tizazshuka - is the main executioner of the shell project
 * @info: structural inheritance
 * Return: nothing just nothing ezra says
 */

void tizazshuka(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		chigiratami(info, "Fork failed");
		antshi(info, 1);
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, inagignakababi()) == -1)
		{
		switch (errno)
		{
			case ENOENT:
				chigiratami(info, "Command not found");
				break;
			case EACCES:
				chigiratami(info, "Permission denied");
				break;
			case EIO:
				chigiratami(info, "I/O error");
				break;
			case ENOMEM:
				chigiratami(info, "Out of memory");
				break;
			default:
				chigiratami(info, "Unknown error occurred");
				break;
		}
		antshi(info, 1);
	}
	}
	else
	{
		wait(&(info->status));
	}
}
