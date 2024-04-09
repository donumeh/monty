#include "monty.h"

/**
 * executeByteCode - executes the bytecode
 * @_bytes: the bytes codes
 * @stack: linked list holding the data pushed to stack
 *
 * Return: 1 on failure, 0 on error
 */

int executeByteCode(bytecode_t **_bytes, stack_t **stack)
{
	instruction_t opcodeInstructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	bytecode_t *head = NULL;

	head = *_bytes;
	while (head != NULL)
	{
		int i;

		stackNumber = head->arg;
		for (i = 0; opcodeInstructions[i].opcode != NULL; i++)
		{
			if (strcmp(head->opcode,opcodeInstructions[i].opcode) == 0)
			{
				opcodeInstructions[i].f(stack,
						head->lineNumber);
				break;
			}
		}

		head = head->next;
	}
	return (1);
}
