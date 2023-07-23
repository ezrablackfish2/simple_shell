#include "gasha.h"

/**
 * main - this is where everything begins our shell starts here ezra and aman
 * @argc: the argument count
 * @argv: the argument value
 * Return: 1 succes 0 great failuere
 */

int main(int argc, char *argv[])
{
	int descriptor;
	int result;
	char *line;
	size_t line_length;
	property file;
	info_t info;
	int built_in_ret;

	line = NULL;
	info.linecount = 0;
	file.linecount_flag = 0;
	descriptor = 0;
	line_length = 0;
	built_in_ret = 0;

	if (argc > 1)
	{
		descriptor = open(argv[1], O_RDONLY);
		if (descriptor < 0)
		{
			perror(argv[1]);
			return (1);
		}
	}

	file.descriptor = descriptor;
	result = zuret(descriptor, argc, argv, line, line_length,
			file, info, built_in_ret);
	return (result);
}
