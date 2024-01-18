#include "monty.h"

/**
 * Global variable that contains all the error types
 * assciated with our source file
 */

int error_code[] = {
	101,
	102,
	104,
	105,
	106,
	'\0'
};

char *error_type[] = {
	"USAGE: monty file\n",
	"Error: malloc failed\n",
	"Error: Can't open file ",
	"Error: fclose malfunction\n",
	": usage: push integer\n",
	"NULL"
};
