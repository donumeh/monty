#include "monty.h"

/**
 * getFileName - get the file name and check if its monty
 * @fileName: the name of the file
 *
 * Return: filename (malloc'ed)
 */

char *getFileName(char *fileName)
{
	char *fileNameCopy;
	int montyFlag;

	fileNameCopy = _strdup(fileName);
	montyFlag = checkIfMontyFile(fileName);
	if (montyFlag == 1)
	{
		free(fileNameCopy);
		return (NULL);
	}
	return (fileNameCopy);
}

/**
 * checkIfMontyFile - checks if the file is a monty file (.m)
 * @fileName: the name of the file
 *
 * Return: 0 if it is, else 1
 */

int checkIfMontyFile(char *fileName)
{
	char *delim = ".\n";
	char *token = NULL;
	char *lastToken = NULL;

	token = strtok(fileName, delim);
	while (token)
	{
		lastToken = token;
		token = strtok(NULL, delim);
	}

	if (strcmp(lastToken, "m") == 0)
		return (0);
	return (1);
}
