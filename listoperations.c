#include "monty.h"

/**
 * byteAdd - adds a node to the end of a byte
 * @_bytes: the head of the byte
 * @opcode: the opcode to save
 * @arg: the arg that follows the opcode
 * @lineNumber: the lineNumber of command
 *
 * Return: 1 on failure, 0 on success
 */

int byteAdd(bytecode_t **_bytes, char *opcode, char *arg, int lineNumber)
{
	bytecode_t *newByte = NULL;

	newByte = malloc(sizeof(bytecode_t));
	if (newByte == NULL)
		return (1);

	newByte->opcode = _strdup(opcode);
	newByte->arg = _strdup(arg);
	newByte->lineNumber = lineNumber;

	if (*_bytes == NULL)
	{
		newByte->next = NULL;
		*_bytes = newByte;
	}
	else
	{
		bytecode_t *head;

		head = *_bytes;
		while (head->next != NULL)
		{
			head = head->next;
		}
		newByte->next = NULL;
		head->next = newByte;
	}

	return (0);
}
