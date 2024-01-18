#include "monty.h"

/**
 * readfile - reads a file line by line
 * @fd: file decriptor of file
 *
 * Return: 1 on error, 0 when otherwise
 */

int readfile_exec(char *filename)
{
	FILE *stream;
	char *lineptr = NULL;
	size_t n = 0, token_alloc = 0, line_number = 0;
	char **instruction = NULL;

	stream = fopen(filename, "r");

	while (getline(&lineptr, &n, stream) != -1)
	{
		instruction = tokenize_opcode(lineptr, &token_alloc);
		line_number++;
		opcode_exec(instruction, line_number);

		freedoubleptr(instruction, token_alloc);
	}

	free(lineptr);
	if (fclose(stream))
		error_handler(105, NULL, 0);

	return (0);
}


/**
 * tokenize_opcode - tokenize the instruction into array of strings
 * @str: str of tokenize
 *
 * Return: ptr to array
 */

char **tokenize_opcode(char *str, size_t *token_alloc)
{
	char *delim = " \n";
	char *str_copy = NULL;
	char *token = NULL;
	char **instruction = NULL;
	int i = 0;

	str_copy = _strdup(str);

	token = strtok(str_copy, delim);
	while (token)
	{
		i++;
		token = strtok(NULL, delim);
	}
	free(str_copy);
	*token_alloc = i + 1;
	instruction = malloc(sizeof(char *) * (i + 1));
	if (instruction == NULL) /* Might need to return NULL to handle mem later */
		error_handler(102, NULL, 0);

	i = 0;
	token = strtok(str, delim);
	while (token)
	{
		instruction[i] = _strdup(token); /* Might need to free */
		i++;
		token = strtok(NULL, delim);
	}
	instruction[i] = NULL;

	return (instruction);
}
