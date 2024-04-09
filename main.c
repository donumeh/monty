#include "monty.h"

char *stackNumber = NULL;
/**
 * main - read and intepret a monty bytecode
 * @argc: the number of arg passed
 * @argv: arg vector. Strings to args passed in CLI
 *
 * Return: Exit success on success else, Exit failure
 */

int main(int argc, char **argv)
{
	bytecode_t *_bytes = NULL;
	stack_t *stack = NULL;
	char *fileName;
	int readFlag;
	int executeFlag;

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
		free(fileName);
		exit(EXIT_FAILURE);
	}

	executeFlag = executeByteCode(&_bytes, &stack);
	if (executeFlag == 1)
	{
		freeBytes(_bytes);
		freeStack(stack);
		/* Free stack here */
		/* free _byte here */
	}

	free(fileName);

	exit(EXIT_SUCCESS);
}
