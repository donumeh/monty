#include "monty.h"


/**
 * error_type - type of error and message to print
 * @num: error number
 *
 * Return: string
 */

char *error_type(int num)
{
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
	int i;

	for (i = 0; error_code[i] != '\0'; i++)
	{
		int n = error_code[i];

		if (n == num)
			return (error_type[i]);
	}
	return (NULL);
}
