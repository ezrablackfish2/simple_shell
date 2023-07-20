#include "gasha.h"

/**
 * antshi - what can i say i free the coming structure
 * @info: i am the inherited strructure
 * @exit_status: me i am the error type
 * Return: no nothing people
 */

void antshi(info_t *info, int exit_status)
{
	if (info != NULL)
	{
		free(info->path);
		free(info->argv);
	}
	exit(exit_status);
}
