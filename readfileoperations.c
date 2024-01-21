#include "monty.h"


/**
 * readFile - reads a file
 * @_bytes: where to store bytes
 * @fileName: the name of file to read
 *
 * Return: 1 on failure, 0 on success
 */

int readFile(bytecode_t **_bytes, char *fileName)
{
	int lineNumber = 0;
	char *linePtr = NULL;
	FILE *stream;
	size_t n = 0;

	stream = fopen(fileName, "r");
	if (stream == NULL)
		return (1);

	while (_getline(&linePtr, &n, stream) != -1)
	{
		lineNumber++;
		if (storeLineInBytes(_bytes, linePtr, lineNumber))
		{
			free(linePtr);
			fclose(stream);
			free(fileName);
			cannotMalloc();
		}
	}

	free(linePtr);
	fclose(stream);
	return (0);
}


/**
 * storeLineInBytes - stores a line of string in _byte linked list
 * @_bytes: the byte linked list to store at
 * @linePtr: the string to tokenize and store
 * @lineNumber: the line number of command
 *
 * Return: 1 if failure, 0 is successful
 */

int storeLineInBytes(bytecode_t **_bytes, char *linePtr, int lineNumber)
{
	int i = 0, byteAddFlag;
	char *parts[2];
	char *token = NULL, *delim = " \n";

	token = strtok(linePtr, delim);
	while (token)
	{
		parts[i] = token;
		i++;
		token = strtok(NULL, delim);
	}
	printf("%s ---- %d\n", parts[0], i);
	/* if (i == 1)
		parts[i] = NULL; */

	printf("%s\n", parts[1]);
	byteAddFlag = byteAdd(_bytes, parts[0], parts[1], lineNumber);
	if (byteAddFlag == 1)
		return (1);
	return (0);
}


