#include "gasha.h"

/**
 * qalatabzi - my man we are going to duplicate this strings
 * @str: you know what am i am a string
 * Return: the duplicate man
 */

char *qalatabzi(char *str)
{
		int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
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
