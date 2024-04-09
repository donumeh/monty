#include "monty.h"

/**
 * freeBytes - frees a linked list
 * @bytes: the linked list to free
 *
 * Return: void
 */

void freeBytes(bytecode_t *_bytes)
{
	bytecode_t *tmp = NULL;

	while (_bytes != NULL)
	{
		tmp = _bytes;
		_bytes = _bytes->next;
		free(tmp);
	}
}


/**
 * freeStack - frees that stack node
 * @stack: the linked list to free
 *
 * Return: void
 */

void freeStack(stack_t *stack)
{
	stack_t *tmp = NULL;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
