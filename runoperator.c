#include "monty.h"

/**
 * push - push a value onto stack
 * @stack: the stack to push
 * @line_number: the line number
 *
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newStack = NULL;

	newStack = malloc(sizeof(stack_t));
	if (newStack == NULL)
	{
		cannotMalloc(); /* Free stacks here */
		return;
	}
	newStack->n = atoi(stackNumber);
	if (newStack->n == 0)
	{
		pushError(line_number);
	}

	if (*stack == NULL)
	{
		newStack->next = *stack;
		newStack->prev = *stack;
		*stack = newStack;
	}
	else
	{
		newStack->prev = NULL;
		newStack->next = *stack;
		(*stack)->prev = newStack;
		*stack = newStack;
	}
}
