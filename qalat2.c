#include "gasha.h"

/**
 * qalatabzi - my man we are going to duplicate this strings
 * @str: you know what am i am a string
 * Return: the duplicate man
 */

char *qalatabzi(char *str)
{
	int len;
	int i;
	char *new_str;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}

	new_str = (char *)malloc(sizeof(char) * len);

	for (i = 0; i <= len; i++)
	{
		new_str[i] = str[i];
	}

	new_str[len + 1] = '\0';

	return (new_str);
}

/**
 * qalatwididirrizmet - what am i the i am )strcmp but with length
 * @str1: i am the string 1
 * @str2: i am string 2 erveyone
 * @n: i am the length everyone
 * Return: like _strcmp
 */

int qalatwididirrizmet(const char *str1, const char *str2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
	{
		return (str1[i] - str2[i]);
	}
	if (str1[i] == '\0')
	{
		return (0);
	}
	i++;
	}

	return (0);
}

/**
 * casqemach - for everyone this might be difficult be i am file writer
 * @c: the character to be written
 * @stream: i am file
 * Return: nothing everyone
 */

void casqemach(char c, FILE *stream)
{
	if (stream == stdout || stream == stderr)
	{
	write(fileno(stream), &c, 1);
	}
}
