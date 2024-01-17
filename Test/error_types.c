#include "monty.h"

/**
 * Global variable that contains all the error types
 * assciated with our source file
 */

int error_code[] = {
	100,
	101,
	102,
	104,
	'\0'
};

char *error_type[] = {
	"File not a monty file type Or Enter 1 .m filename only\n",
	"USAGE: monty file\n",
	"Error: malloc failed\n",
	"Error: Can't open file ",
	"NULL"
};
