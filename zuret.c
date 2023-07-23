#include "gasha.h"

/**
 * zuret - as aman and ezra implies this is the main loop for our shell
 * @descriptor: this tells us if a file is open or not ezra
 * @argc: this tell us argument count said aman
 * @argv: is the argument values you first wrote ezra
 * @line: this is the line that will be read ezra
 * @line_length: is the length of the line to be read we said
 * @file: is the structure that will get in mesemeranabi ezra
 * @info: is the command to be executed structure aman
 * @built_in_ret: is the returning of status of execution ezra
 * Return: 0 success and -1 error
 */

int zuret(int descriptor, int argc, char **argv, char *line,
		size_t line_length, property file, info_t info,
		int built_in_ret)
{
	while (1)
	{
		info.linecount++;
		if (file.descriptor != 0 && file.linecount_flag == 0)
			fayle(file, line, line_length);
		else
		{
			if (isatty(STDIN_FILENO))
				teiyineyatami();
			fflush(stdout);
			if (mesmeranbabi(&line, &line_length, 0) == -1)
				break;
			if (line_length > 0)
			{
				anesash(&info, argc, argv, line);
				built_in_ret = siraagigni(&info);
				if (built_in_ret == -2)
					break;
				else if (built_in_ret == -1)
				{
					info.path = info.argv[0];
					agignaqtacha(&info);
				}
			}
		}
		netsaawchi(&info, line);
	}
	if (descriptor != 0)
		close(descriptor);
	return (0);
}

/**
 * fayle - is the file reading mimiver of mesmeranbabi
 * @file: to be read for line for only files
 * @line: is the line to be read and stored
 * @line_length: is the length of the line in stdfile
 * Return: nothing ezra no no
 */

void fayle(property file, char *line, size_t line_length)
{
	while (mesmeranbabi(&line, &line_length, file.descriptor) != -1)
	{
		if (line_length > 0)
		{
			free(line);
		}
		else
		{
			break;
		}
	}
	file.linecount_flag = 1;
}

/**
 * anesash - this intializes ezra's builtin info
 * @info: this is the structure property we wanted to input for stdin
 * @argc: the argument count you wrote when entering shell ezra
 * @argv: the argument variables we wanted
 * @line: is the line we wanted to read in stdin
 * Return: nothing just nothing
 */

void anesash(info_t *info, int argc, char **argv, char *line)
{
			info->path = line;
			info->argv = NULL;
			info->pipefd[0] = -1;
			info->pipefd[1] = -1;
			info->status = -1;
			info->left_redirect_from_fd = -1;
			info->argc = argc;
			info->arg = qalatabzi(line);
			info->argv = NULL;
			info->shell = argv[0];
			kefai(info);
}

/**
 * netsaawchi - this frees all ezra and aman's info structure built
 * @info: the executed commands all property
 * @line: the line we read from before
 * Return: nothing
 */

void netsaawchi(info_t *info, char *line)
{
	int i;

		if (line != NULL)
		{
			free(line);
			line = NULL;
		}
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
}
