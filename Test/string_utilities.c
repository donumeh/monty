#include "monty.h"

/**
 * _strdup - duplicate a string
 * @str: string to duplicate
 *
 * Return: pointer to a new str
 */

char *_strdup(char *str)
{
	char *str_copy;

	str_copy = malloc(sizeof(char) * strlen(str) + 1);
	if (str_copy == NULL)
		error_handler(102, NULL);

	strcpy(str_copy, str);
	return (str_copy);
}


