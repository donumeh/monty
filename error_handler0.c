#include "monty.h"

/**
 * error_handler - handles error that occurs in execution
 * @error_c: error code type
 *
 * Return: void
 */

void error_handler(int error_c, const char *msg)
{
	int i;

	for (i = 0; error_code[i] != '\0'; i++)
	{
		if (error_code[i] == error_c)
		{
			write(2, error_type[i], strlen(error_type[i]));
			if (error_c == 104)
			{
				write(2, msg, strlen(msg));
				write(2, "\n", strlen("\n"));
			}
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * ifmontyfile - checks if its a .m extension
 * @filename: name of file
 *
 * Return: -1 if not a monty file
 */

int ifmontyfile(char *filename)
{
	char *token;
	char *filename_copy;
	char *delim = ".\n";
	char **arr = NULL;
	size_t i = 0;

	filename_copy = _strdup(filename);
	token = strtok(filename, delim);

	while (token)
	{
		i++;
		token = strtok(NULL, delim);
	}

	arr = malloc(sizeof(char *) * (i + 1));
	if (arr == NULL)
		error_handler(102, NULL);

	i = 0;
	token = strtok(filename_copy, delim);

	while (token)
	{
		arr[i] = _strdup(token);
		i++;
		token = strtok(NULL, delim);
	}
	arr[i] = NULL;
	free(filename_copy);

	if (arr[i - 1][0] != 'm')
	{
		freedoubleptr(arr, i);
		return (1);
	}
	freedoubleptr(arr, i);
	return (0);
}
