#include "monty.h"

/**
 * error_handler - handles error that occurs in execution
 * @error_c: error code type
 * @msg: the error message
 * @line_number: the line number
 *
 * Return: void
 */

void error_handler(int error_c, const char *msg, int line_number)
{
	if (error_c == 106)
	{
		char c = line_number + '0';

		write(2, "L", 1);
		write(2, &c, 1);
	}
	write(2, error_type(error_c), strlen(error_type(error_c)));
	if (error_c == 104)
	{
		write(2, msg, strlen(msg));
		write(2, "\n", strlen("\n"));
	}
	/* Check if head is NULL and if not NULL free nodes */
	exit(EXIT_FAILURE);
}

/**
 * ifmontyfile - checks if its a .m extension
 * @filename: name of file
 *
 * Return: -1 if not a monty file
 */

int ifmontyfile(char *filename)
{
	char *token = NULL;
	char *last_token = NULL;
	char *delim = ".\n";

	token = strtok(filename, delim);

	while (token)
	{
		last_token = token;
		token = strtok(NULL, delim);
	}

	if (strcmp(last_token, "m") != 0)
	{
		return (1);
	}
	return (0);
}

/**
 * isInteger - checks if string can be converted to integer
 * @str: the string to check if can be parsed to int
 *
 * Return: 0 if can be parsed, else 1
 */

int isInteger(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
	}

	return (0);
}
