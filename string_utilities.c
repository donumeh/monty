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

	str_copy = malloc(sizeof(char) * (strlen(str) + 1));
	if (str_copy == NULL)
		error_handler(102, NULL, 0);

	strcpy(str_copy, str);
	return (str_copy);
}

/**
 * _getline - gets line from file
 * @lineptr: store line here
 * @n: number of bytes copied
 * @stream: the file stream
 *
 * Return: 0 on success, -1 on failure
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t i = 0;
	int c;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return -1;

	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
			return -1;
	}
	
	while ((c = fgetc(stream)) != EOF)
	{
		if (i >= *n - 1)
		{
			size_t new_size = *n * 2;
			char *new_lineptr = (char *)realloc(*lineptr, new_size);
			if (new_lineptr == NULL)
			{
				free(*lineptr);
				*lineptr = NULL;
				*n = 0;
				return -1;
			}
			*lineptr = new_lineptr;
			*n = new_size;
		}
		(*lineptr)[i++] = (char)c;
		if (c == '\n')
			break;
	}
	
	if (i == 0 && c == EOF)
		return -1;
	(*lineptr)[i] = '\0';
    return i;
}

