#include "gasha.h"

/**
 * qalatrizmet - we wanted to get the length of string us mean ezra and aman
 * @str: the length that we wanted ezra and aman
 * Return: the size or lenngth aman and ezra of the string
 */

int qalatrizmet(const char *str)
{
	int len;

	len = 0;
	if (!str)
	{
		return (0);
	}

	while (*str != '\0')
	{
		len = len + 1;
		str = str + 1;
	}

	return (len);
}
/**
 * qalatwididir - ezra and aman wanted what the copy of the string man
 * @str1: first string ezra wanted
 * @str2: seconf string aman wanted
 * Return: zero if two string are equal man
 */

int qalatwididir(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return (-1);
		}
		i++;
	}

	if (str1[i] == '\0' && str2[i] == '\0')
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
/**
 * fideagni - ezra wanted also aman that we wanted that one character gotten
 * @str: the first ezrians stringalous
 * @character: my god we need this character everyone
 * Return: that str we always wanted
 */

char *fideagni(char *str, char *character)
{
	int len_str, len_char;
	char *res;
	int i;

	len_str = 0;
	len_char = 0;
	while (*(character + len_char) != '\0')
		len_char++;

	while (*(str + len_str) != '\0')
		len_str++;

	for (i = 0; i < len_char; i++)
	{
		if (*(character + i) != *(str + i))
		{
			return ((char *)NULL);
		}
	}

	res = (char *)str;
	return (res);
}

/**
 * qalatagenagn - the joinacne by ezra the strings
 * @dest: oh my god the source to be joined
 * @src: we want this boy to be joined
 * Return: the new jained man
 */

char *qalatagenagn(char *dest, const char *src)
{
	int dest_length;
	int i;
	int src_length;

	dest_length = 0;
	src_length = 0;
	while (dest[dest_length] != '\0')
	{
		dest_length++;
	}

	while (src[src_length] != '\0')
	{
		src_length++;
	}

	for (i = 0; i < src_length; i++)
	{
		dest[dest_length + i] = src[i];
	}

	dest[dest_length + i] = '\0';

	return (dest);
}
/**
 * qalatqegni - almighty the copier of the strings
 * @destination: i am to be the copy comebacker
 * @source: i am the source man
 * Return: the copied new man
 */

char *qalatqegni(char *destination, char *source)
{
	int i;

	i = 0;

	if (destination == source || source == 0)
	{
		return (destination);
	}

	while (source[i] != '\0')
	{
		destination[i] = source[i];
		i++;
	}

	destination[i] = '\0';

	return (destination);
}
