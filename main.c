#include "monty.h"

/**
 * main - read and intepret a monty bytecode
 * @argc: the number of arg passed
 * @argv: arg vector. Strings to args passed in CLI
 *
 * Return: Exit success on success else, Exit failure
 */

int main(int argc, char **argv)
{
	bytecode_t *_bytes = NULL, *temp;
	char *fileName;
	int readFlag;

	if (argc != 2)
		noFileError();

	fileName = getFileName(argv[1]);

	if (fileName == NULL)
	{
		notMontyError(argv[1]);
		exit(EXIT_FAILURE);
	}
	
	readFlag = readFile(&_bytes, fileName);
	if (readFlag == 1)
	{
		notMontyError(fileName);
		exit(EXIT_FAILURE);
	}

	while (_bytes != NULL)
	{
		printf("%s - %s - %d\n", _bytes->opcode, _bytes->arg,
				_bytes->lineNumber);
		temp = _bytes;
		_bytes = _bytes->next;
		free(temp->opcode);
		free(temp->arg);
		free(temp);
	}

	free(fileName);

	exit(EXIT_SUCCESS);
}
