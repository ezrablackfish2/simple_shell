#include "gasha.h"

/**
 * zuret - is where the loop of shell is executed this is the the main thing
 * @descriptor: is the file describing whether open or not
 * @argc: argument count
 * @argv: the argument value
 * Return: perfect 1 failurity 0
 */

int zuret(int descriptor, int argc, char **argv)
{
	char *line;
	size_t line_length;
	property file;
	info_t info;

	line = NULL, info.linecount = 0, file.linecount_flag = 0,
	     file.descriptor = descriptor;
	while (1)
	{
		info.linecount++;
		if (file.descriptor != 0 && file.linecount_flag == 0)
		{
			while (mesmeranbabi(&line, &line_length, file.descriptor) != -1)
			{
				if (line_length > 0)
					free(line);
			else
				break;
			}
		}
		else
		{
			siket(line, line_length, &info, argc, argv, &file);
		}
	}
	if (descriptor != 0)
		close(descriptor);
	return (0);
}

/**
 * siket - if the getline mimicer worked well then it is going here so
 * @line: is the line that is read by mimicer
 * @line_length: is the length of the line read
 * @info: structural inheritance
 * @argc: is the argument counter
 * @argv: is the value of argument values you wrote
 * @file: is the teller of interactiviness aman and ezra
 * Return: nothing just nothing
 */

void siket(char *line, size_t line_length, info_t *info,
		int argc, char **argv, property *file)
{
	int built_in_ret;

			if (megenagna(file))
			{
				teiyineyatami();
			}
			fflush(stdout);
			if (mesmeranbabi(&line, &line_length, 0) == -1)
				return;
			if (line_length > 0)
			{
			anesash(info, line, argc, argv);
			kefai(info);
			built_in_ret = siraagigni(info);
			if (built_in_ret == -2)
			{
				free(line);
				free(info->argv[0]);
				free(info->argv);
				return;
			}
			else if (built_in_ret == -1)
			{
				info->path = info->argv[0];
				agignaqtacha(info);
			}
			free(line);
			free(info->argv[0]);
			free(info->argv);
			}
			if (!megenagna(file))
			{
				exit(info->status);
			}
}

/**
 * anesash - is the initializer before the loop is started
 * @info: is the structural inheritance
 * @line: the line read by the sheller of all
 * @argc: is the argument count
 * @argv: is the value of argument value
 * Return: nothing just nothing
 */

void anesash(info_t *info, char *line, int argc, char **argv)
{
		info->path = line;
		info->argv = NULL;
		info->pipefd[0] = -1;
		info->pipefd[1] = -1;
		info->status = -1;
		info->left_redirect_from_fd = -1;
		info->argc = argc;
		info->arg = qalatabzi(line);
		info->argv = malloc(sizeof(argc));
		info->argv[0] = NULL;
		info->argv[1] = NULL;
		info->shell = argv[0];
		return;
}

/**
 * megenagna - returns true if shell is interactive mode
 * @file: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int megenagna(property *file)
{
	return (isatty(STDIN_FILENO) && file->descriptor <= 2);
}
