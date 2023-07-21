#include "gasha.h"

/**
 * nibabanesash - ezra and aman awantes to make line before 0 descrive
 * @reader: the structure containg the property of the line
 * @descriptor: tell file if it is open or not ezra aman
 * Return: nothing everyone ezra
 */

void nibabanesash(sline *reader, int descriptor)
{
	reader->descriptor = 0;
	memset(reader->readingplace, 0, sizeof(reader->readingplace));
	reader->index = 0;
	reader->length = 0;

	if (reader->descriptor != descriptor)
	{
		reader->descriptor = descriptor;
		reader->index = 0;
		reader->length = 0;
	}

	if (descriptor == -1)
	{
		reader->descriptor = 0;
		reader->index = 0;
		reader->length = 0;
	}
}

/**
 * kegelashanbabi - get knowledge from descriptoe to work on mimic
 * @descriptor: file telling open or not
 * @reader: thebuffer
 * Return: the length from the descriptor i mean the property
 */

ssize_t kegelashanbabi(int descriptor, sline *reader)
{
	ssize_t r;

	r = mesmeranbib(descriptor, reader->readingplace + reader->length,
		MAX_LINE_LENGTH - reader->length);
	if (r < 0)
	{
		return (-1);
	}
	if (r == 0 && reader->length == 0)
	{
		return (-1);
	}
	if (r == 0)
	{
		return (0);
	}
	reader->length += r;
	return (r);
}

/**
 * gimashanbabi - the half part of our mimicer getline it tell other
 * @line_length: the length of the line at first
 * @reader: the empty buffer
 * @line: this is the thing we want the main we will return the line
 * Return: an number of previous read size
 */

int gimashanbabi(sline *reader, ssize_t *line_length, char **line)
{
	int i;
	char *p = reader->readingplace + reader->index;
	char *end = reader->readingplace + reader->index + reader->length;

	while (p < end && *p != '\n')
	{
		p++;
	}

	if (p < end)
	{
	*line_length = p - (reader->readingplace + reader->index);
	*line = (char *)malloc((*line_length + 1) * sizeof(char));
	if (*line == NULL)
	{
		return (-1);
	}
	for (i = 0; i < *line_length; i++)
	{
		(*line)[i] = reader->readingplace[reader->index + i];
	}
	(*line)[*line_length] = '\0';
	reader->index += *line_length + 1;
	reader->length -= *line_length + 1;
	if (reader->length == 0)
	{
		reader->index = 0;
	}
	return (1);
	}

	if (reader->length == MAX_LINE_LENGTH)
	{
		reader->index = 0;
		reader->length = 0;
	}
	return (0);
}
/**
 * mesmeranbabi - now hear me this is the real deal this is the mimic getline
 * @lineptr: the buffer to be copied to finally
 * @n: the reading number size
 * @descriptor: file opening or not
 * Return: the length of the line
 */


ssize_t mesmeranbabi(char **lineptr, size_t *n, int descriptor)
{
	static sline reader;
	ssize_t line_length = 0;
	ssize_t r;
	int result;

	nibabanesash(&reader, descriptor);

	while (1)
	{
		r = kegelashanbabi(descriptor, &reader);
		if (r < 0)
		{
		return (-1);
		}
		if (r == 0)
		{
			break;
		}
		result = gimashanbabi(&reader, &line_length, lineptr);
		if (result == -1)
		{
			return (-1);
		}
		if (result == 1)
		{
			*n = line_length;
			return (line_length);
		}
	}

	*lineptr = NULL;
	*n = 0;
	return (0);
}
