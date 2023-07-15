#include "terminal.h"

/**
 * _strlen - Calculate the length of a string.
 * @str: The input string.
 *
 * Return: The length of the string.
 */
int _strlen(const char *str)
{
	int len = 0;

	if (!str)
	{
		return (0);
	}

	while (*str != '\0')
	{
		len = len + 1;
		str = str + 1;
	}

	return len;
}

/**
 * _strcmp - Compare two strings.
 * @str1: The first string to compare.
 * @str2: The second string to compare.
 *
 * Return:
 *   -1 if str1 is less than str2,
 *    0 if str1 is equal to str2,
 *    1 if str1 is greater than str2.
 */
int _strcmp(char *str1, char *str2)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return -1;
		}
		i++;
	}

	if (str1[i] == '\0' && str2[i] == '\0')
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

/**
 * get_char - Find the first occurrence of a character in a string.
 * @str: The input string.
 * @character: The character to search for.
 *
 * Return: A pointer to the first occurrence of the character in the string,
 *         or NULL if the character is not found.
 */
char *get_char( char *str, char *character)
{
	int len_str = 0, len_char = 0;
	char *res;

	while (*(character + len_char) != '\0')
		len_char++;

	while (*(str + len_str) != '\0')
		len_str++;

	for (int i = 0; i < len_char; i++)
	{
		if (*(character + i) != *(str + i))
			return (char *)NULL;
	}

	res = (char *)str;
	return res;
}

/**
 * _strcat - Concatenate two strings.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: The concatenated string.
 */
char *_strcat(char *dest,const char *src)
{
	int dest_length = 0;
	int src_length = 0;

	while (dest[dest_length] != '\0')
	{
		dest_length++;
	}

	while (src[src_length] != '\0')
	{
		src_length++;
	}

	int i;
	for (i = 0; i < src_length; i++)
	{
		dest[dest_length + i] = src[i];
	}

	dest[dest_length + i] = '\0';

	return dest;
}

/**
 * _strcpy - Copy a string.
 * @destination: The destination string.
 * @source: The source string.
 *
 * Return: The copied string.
 */
char *_strcpy(char *destination, char *source)
{
	int i = 0;

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

	return destination;
}

/**
 * _strdup - Duplicate a string.
 * @str: The input string.
 *
 * Return: The duplicated string.
 */
char *_strdup(char *str)
{
	int len = 0;
	char *new_str;

	while (str[len] != '\0')
	{
		len++;
	}

	new_str = (char *)malloc(sizeof(char) * len);

	for (int i = 0; i <= len; i++)
	{
		new_str[i] = str[i];
	}

	new_str[len + 1] = '\0';

	return new_str;
}

/**
 * _puts - Print a string.
 * @str: The string to print.
 */
void _puts(char *str)
{
	int i = 0;

	if (str == NULL)
	{
		return;
	}

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i += 1;
	}

	return;
}

/**
 * _putchar - Write a character to stdout.
 * @c: The character to write.
 *
 * Return: 1 on success.
 */
int _putchar(char c)
{
	int buff_index = 0;
	char buffer[256];

	if (c == '@' || buff_index >= 256)
	{
		write(1, buffer, buff_index);
		buff_index = 0;
	}

	if (c != '@')
		buffer[buff_index++] = c;

	return (1);
}

/**
 * _strchrlast - Find the last occurrence of a character in a string.
 * @s: The input string.
 * @c: The character to search for.
 *
 * Return: A pointer to the last occurrence of the character in the string,
 *         or NULL if the character is not found.
 */
char *_strchrlast(char *s, char c)
{
	char *ret = NULL, *p;

	while ((p = get_char(s, &c)))
	{
		ret = p;
		s = p + 1;
	}
	return (ret);
}

int _strncmp(const char* str1, const char* str2, size_t n) {
    size_t i = 0;

    while (i < n) {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        if (str1[i] == '\0') {
            return 0;
        }
        i++;
    }

    return 0;
}


void _putc(char c, FILE* stream) {
    if (stream == stdout || stream == stderr) {
        write(fileno(stream), &c, 1);
    }
}
