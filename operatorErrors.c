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
	char c = lineNumber + '0';

	errMsg = ": usage: push integer\n";
	write(2, "L", strlen("L"));
	write(2, &c, 1);
	write(2, errMsg, strlen(errMsg));
}
