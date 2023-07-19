#include "gasha.h"

/**
 * akababiagni - my i get environment everyone
 * @variable: am the real deal of variable to be exposed
 * Return: the environent values
 */

char *akababiagni(const char *variable)
{

	size_t var_length;
	char **env = environ;

	if (variable == NULL)
	{
		return (NULL);
	}

	var_length = qalatrizmet(variable);

	while (*env != NULL)
	{
	if (qalatwididirrizmet(variable, *env, var_length) == 0
		&& (*env)[var_length] == '=')
	{
		return (&((*env)[var_length + 1]));
	}
	env++;
	}

	return (NULL);
}
