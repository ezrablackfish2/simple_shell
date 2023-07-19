#include "gasha.h"

/**
 * agignaqtacha - ezra wanted to find the place where we find the executionabil
 * @info: the structural inheritance
 * Return: nothing just nothing
 */

void agignaqtacha(info_t *info)
{
	char *p = NULL;
	int r = 0, place = 0;

	while (info->arg[r])
	{
		place += !aqimlik(info->arg[r], " \t\n") ? 1 : 0;
		r++;
	}

	p = (!place) ? NULL : aqtachagni(info, akababiagni("PATH"), info->argv[0]);

	if (p)
	{
		info->path = p;
		tizazshuka(info);
	}
	else
	{
	if ((akababiagni("PATH") || info->argv[0][0] == '/')
			&& tizaznew(info, info->argv[0]))
		tizazshuka(info);
	else if (*(info->arg) != '\n')
		chigiratami(info, "not found\n");
	}
}

/**
 * aqtachagni - the place where we can find the path environemtn values divided
 * @info: the structural inheritance
 * @placestr: the place where the string is to be taken
 * @cmd: the commands to be execeuted by us
 * Return: the concatinated command fo you to execute
 */

char *aqtachagni(info_t *info, char *placestr, char *cmd)
{
	int r = 0, posi = 0;
	char *place;

	if (!placestr)
		return (NULL);
	else if ((qalatrizmet(cmd) > 2) && fideagni(cmd, "./"))
	{
		if (tizaznew(info, cmd))
			return (cmd);
		else
			return (NULL);
	}
	else
	{
	while (1)
	{
		if (!placestr[r] || placestr[r] == ':')
		{
			place = fidelbizet(placestr, posi, r);
		if (!*place)
			qalatagenagn(place, cmd);
		else
		{
			qalatagenagn(place, "/");
			qalatagenagn(place, cmd);
		}
		if (tizaznew(info, place))
			return (place);
		if (!placestr[r])
			break;
		posi = r;
		}
	r++;
	}
	return (NULL);
	}
}

/**
 * tizaznew - whether it is command or not we want to know ezra
 * @info: the information that i need for me onherited
 * @place: the place where the command is read
 * Return: yes 1 or no 0
 */

int tizaznew(info_t *info, char *place)
{
	struct stat st;

	(void)info;
	return ((!place || stat(place, &st)) ? 0 :
		(st.st_mode & S_IFREG) ? 1 :
		0);
}

/**
 * fidelbizet - we wanted to multiply ezra strings
 * @placestr: is the place where string is to be taken
 * @start: the starting string
 * @stop: the stopping place for strinG
 * Return: the duplciated string
 */

char *fidelbizet(char *placestr, int start, int stop)
{
	static char place[1024];
	int m = 0, u = 0;

	for (u = 0, m = start; m < stop; m++)
		(placestr[m] != ':') ? (place[u++] = placestr[m]) : 0;
	place[u] = 0;
	return (place);
}
