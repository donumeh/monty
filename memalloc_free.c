#include "monty.h"

/**
 * freedoubleptr - frees a double pointer
 * @ptr: ptr to free
 * @i: size of malloc'ed
 *
 * Return: void
 */


void freedoubleptr(char **ptr, int i)
{
	int j;

	for (j = 0; j < i && ptr[j] != NULL; j++)
	{
		free(ptr[j]);
	}
	free(ptr);
}
