#include "monty.h"

/**
 * nofileerror - returns an error if not file passed
 * or multiple files passed
 *
 * Return: void
 */

void noFileError(void)
{
	char *err_msg;

	err_msg = "USAGE: monty file\n";
	write(2, err_msg, strlen(err_msg));
	exit(EXIT_FAILURE);
}


/**
 * notMontyError - file is not a monty file error
 * @fileName: filename passed
 *
 * Return: void
 */

void notMontyError(char *fileName)
{
	char *err_msg;

	err_msg = "Error: Can't open file ";
	write(2, err_msg, strlen(err_msg));
	write(2, fileName, strlen(fileName));
	write(2, "\n", strlen("\n"));
}

/**
 * cannotMalloc - malloc failed error
 *
 * Return: void
 */

void cannotMalloc(void)
{
	char *errMsg;

	errMsg = "Error: malloc failed\n";
	write(2, errMsg, strlen(errMsg));

	exit(EXIT_FAILURE);
}
