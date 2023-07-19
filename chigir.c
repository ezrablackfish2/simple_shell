#include "gasha.h"
/**
 * chigiratami - we needed to print the error like a real print errorer
 * @info: the structural inheritance
 * @message: the message we needed to insert in to exenorate
 * Return: notjhing just nothing
 */

void chigiratami(info_t *info, const char *message)
{
	char *linecount;
	int message_length;
	int argv_length;
	int shell_length;
	int line_length;
	char *error_message;
	ssize_t bytes_written;

	linecount = qutirwedeqal(info->linecount, 10, 0);
	message_length = qalatrizmet(message);
	argv_length = qalatrizmet(info->argv[0]);
	shell_length = qalatrizmet(info->shell);
	line_length = qalatrizmet(linecount);
	error_message = (char *)malloc(message_length
			+ line_length + argv_length + shell_length + 7);
	if (info == NULL)
		return;

	if (error_message == NULL)
	{
		perror("Error: Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	qalatqegni(error_message, info->shell);
	qalatagenagn(error_message, ": ");
	qalatagenagn(error_message, linecount);
	qalatagenagn(error_message, ": ");
	qalatagenagn(error_message, info->argv[0]);
	qalatagenagn(error_message, ": ");
	qalatagenagn(error_message, message);
	bytes_written = write(STDERR_FILENO,
			error_message, qalatrizmet(error_message));
	if (bytes_written == -1)
	{
		perror("Error: Write failed");
		free(error_message);
		exit(EXIT_FAILURE);
	}
	free(error_message);
}

/**
 * qutirwedeqal - we wanted to change number to string
 * @number: the number everyone
 * @base: the base which the number is basedd
 * @flags: conditions to make the number work
 * Return: we wanted to return the converted string number
 */

char *qutirwedeqal(long int number, int base, int flags)
{
	static char *charArray;
	static char buffer[50];
	char sign = 0;
	char *strPtr;
	unsigned long int quotient;

	if (!(flags) && number < 0)
	{
		quotient = -number;
		sign = '-';
	}
	else
	{
	quotient = number;
	}
	charArray = "0123456789ABCDEF";
	strPtr = &buffer[49];
	*strPtr = '\0';
	do {
		*--strPtr = charArray[quotient % base];
		quotient /= base;
	} while (quotient != 0);

	if (sign)
	*--strPtr = sign;
	return (strPtr);
}
