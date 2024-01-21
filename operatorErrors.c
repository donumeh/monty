#include "monty.h"

/**
 * pushError - push error
 * @lineNumber: line number of error
 *
 * Return: void
 */

void pushError(unsigned int lineNumber)
{
	char *errMsg;

	errMsg = ": usage: push integer\n";
	write(2, "L", strlen("L"));
	write(2, &(lineNumber + '0'), 1);
	write(2, errMsg, strlen(errMsg));
}
