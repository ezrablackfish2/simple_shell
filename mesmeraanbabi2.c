#include "gasha.h"

/**
 * mesmeranbib - this uses read to find length and read the buffer file
 * @descriptor: file describing or not integer
 * @buffer: the space where something is read
 * @max_length: the length of input user
 * Return: length of read input or file
 */

ssize_t mesmeranbib(int descriptor, char *buffer, ssize_t max_length)
{
	ssize_t total_read;
	ssize_t bytes_read;
	char ch;

	bytes_read = 0;
	total_read = 0;
	while (total_read < max_length - 1)
	{
		bytes_read = read(descriptor, &ch, 1);

	if (bytes_read == -1)
	{
		return (-1);
	}
	else if (bytes_read == 0)
	{
		break;
	}
	else
	{
		buffer[total_read] = ch;
		total_read++;
	if (ch == '\n')
	{
		break;
	}
	}
	}

	buffer[total_read] = '\0';
	return (total_read);
}

/**
 * ikaanbib - this right here read for files only not input
 * @descriptor: file describing integer
 * @buffer: the emprty space where things go to be done
 * Return: length of the file
 */

ssize_t ikaanbib(int descriptor, char **buffer)
{
	off_t file_size;
	ssize_t buffer_size;
	ssize_t total_read;

	file_size = lfelagi(descriptor, 0, SEEK_END);
	if (file_size == -1)
	{
		return (-1);
	}

	buffer_size = file_size + 1;
	*buffer = (char *)malloc(buffer_size * sizeof(char));
	if (*buffer == NULL)
	{
		return (-1);
	}

	lfelagi(descriptor, 0, SEEK_SET);
	total_read = read(descriptor, *buffer, buffer_size - 1);
	if (total_read == -1)
	{
		free(*buffer);
		return (-1);
	}

	(*buffer)[total_read] = '\0';
	return (total_read);
}

/**
 * lfelagi - this right here is used for file seeking purpose to flush it
 * @descriptor: file describing or not thing
 * @offset: is file switching or oning term
 * @whence: is the start at to do things begin
 * Return: the offset number
 */

off_t lfelagi(int descriptor, off_t offset, int whence)
{
	off_t current_offset;
	off_t new_offset;
	off_t file_size;

	current_offset = lfelagi(descriptor, 0, SEEK_CUR);
	new_offset = current_offset;
	if (whence == SEEK_SET)
	{
		new_offset = offset;
	}
	else if (whence == SEEK_CUR)
	{
		new_offset = current_offset + offset;
	}
	else if (whence == SEEK_END)
	{
		file_size = lfelagi(descriptor, 0, SEEK_END);
		new_offset = file_size + offset;
	}

	lfelagi(descriptor, new_offset, SEEK_SET);
	return (new_offset);
}

/**
 * afsash - what can i say this here ezra did a flush style mimicer of fflush
 * @stream: the file itself could be stdin or stdout aman said
 * Return: 1 succes ezra 0 faliure aman
 */

int afsash(FILE *stream)
{
	if (stream == stdout)
	{
		casqemach('\n', stream);
		return (0);
	}
	else
	{
		return (EOF);
	}
}
