#include "gasha.h"

int zuret(int descriptor, int argc, char **argv)
{
	char* line;
	int i;
	size_t line_length;
	property file;
	info_t info;
	int built_in_ret;

	line = NULL;
	info.linecount = 0;
	file.linecount_flag = 0;
	file.descriptor = descriptor;
	while (1)
	{
		info.linecount++;
		if (file.descriptor != 0 && file.linecount_flag == 0)
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
		else
		{
			if (isatty(STDIN_FILENO))
				teiyineyatami();
			fflush(stdout);
			if (mesmeranbabi(&line, &line_length, 0) == -1)
			{
				break;
			}
			if (line_length > 0)
			{
			info.path = line;  
			info.argv = NULL;  
			info.pipefd[0] = -1;  
			info.pipefd[1] = -1;  
			info.status = -1;  
			info.left_redirect_from_fd = -1; 
			info.argc = argc;
			info.arg = qalatabzi(line);
			info.argv = NULL;
			info.shell = argv[0];
			kefai(&info);
			built_in_ret = siraagigni(&info);
			if (built_in_ret == -2)
			{
				break;
			}
			else if (built_in_ret == -1)
			{
				info.path = info.argv[0];
				agignaqtacha(&info);
			}
			}
		}
		if (line != NULL)
		{
			free(line);
			line = NULL;
		}
		if (info.arg!= NULL)
		{
			free(info.arg);
			info.arg = NULL;		
		}
		if (info.argv != NULL)
		{
			for (i = 0; info.argv[i]; i++)
				free(info.argv[i]);
			free(info.argv);
			info.argv = NULL;
		}

	}
	if (descriptor != 0)
	{
		close(descriptor);
	}
	return (0);
}
