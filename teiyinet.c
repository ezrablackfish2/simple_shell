#include "gasha.h"

/**
 * teiyineyatami - what can i say i am printer you see in shell
 * Return: nothing just nothing
 */

void teiyineyatami(void)
{
	char cwd[1024];
	char hostname[1024];
	char username[1024];
	time_t rawtime;
	struct tm *info;
	char time_buffer[80];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd");
		exit(EXIT_FAILURE);
	}

	if (gethostname(hostname, sizeof(hostname)) != 0)
	{
		perror("gethostname");
		exit(EXIT_FAILURE);
	}

	time(&rawtime);
	info = localtime(&rawtime);
	strftime(time_buffer, sizeof(time_buffer), "%Y/%m/%d", info);
	atim("{{<<Ezra>>}} Shell and aman");
	if (strcmp(cwd, "/") == 0)
	{
		atim("$ ");
	}
	else
	{
		atim(":~");
		atim(cwd);
		atim("$ ");
	}
}
