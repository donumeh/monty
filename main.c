#include "monty.h"

/**
 * main - executes a monty byte code
 * @argc: argument counter
 * @argv: commands entered into command line
 *
 * Return: Exit(1) if error encoutered else exit(0)
 */

int main(int argc, UNUSED char **argv)
{
	int fd;
	char *filename;
	int readfile_flag;


	if (argc != 2)
		error_handler(101, NULL);
	filename = _strdup(argv[1]);

	if (ifmontyfile(argv[1]) == 1)
		error_handler(101, NULL);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_handler(104, filename);

	readfile_flag = readfile_exec(fd);
	printf("%d\n", readfile_flag);

	close(fd);
	free(filename);

	exit(EXIT_SUCCESS);
}
