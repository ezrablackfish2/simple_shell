#include "gasha.h"

/**
 * atim - mimics printf
 * @str: the printed string
 * Return: nothing everyone
 */

void atim(char *str)
{
	int len;

	if (!str)
	{
		return;
	}

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}

	write(1, str, len);
}
