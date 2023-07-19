#include "gasha.h"

/**
 * main - this is where everything begins our shell starts here ezra and aman
 * @argc: the argument count
 * @argv: the argument value
 * Return: 1 succes 0 great failuere
 */

int main(int argc, char *argv[])
{
	int descriptor;
	int result;

	descriptor = 0;

	if (argc > 1)
	{
		descriptor = open(argv[1], O_RDONLY);
		if (descriptor < 0)
		{
			perror(argv[1]);
			return (1);
		}
	}

	result = zuret(descriptor, argc, argv);
	return (result);
}
