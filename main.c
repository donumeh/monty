#include "monty.h"

/**
 * main - executes a monty byte code
 * @argc: argument counter
 * @argv: commands entered into command line
 *
 * Return: Exit(1) if error encoutered else exit(0)
 */

int main(int argc, char **argv)
{
	char *filename;

	if (argc != 2)
		error_handler(101, NULL, 0);
	filename = _strdup(argv[1]);

	if (ifmontyfile(argv[1]) == 1)
		error_handler(101, NULL, 0);

	readfile_exec(filename);


	free(filename);

	exit(EXIT_SUCCESS);
}
