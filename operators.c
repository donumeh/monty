#include "monty.h"

/**
 * push - push an argument onto stack
 * @stack: the stack
 * @line_number: the line_number of command
 *
 * Return: void
 */

void push(stack_t **stack, UNUSED unsigned int line_number)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		error_handler(102, NULL, 0);

	new_node->n = stack_number;

	if (*stack == NULL)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*stack = new_node;
	}
	else
	{
		new_node->prev = NULL;
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}


/**
 * pall - prints the values on stack
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */

void pall(stack_t **stack, UNUSED unsigned int line_number)
{
	stack_t *head;

	if (stack == NULL || *stack == NULL)
		return;

	head = *stack;

	while (head != NULL)
	{
		/* printf("%d\n", head->n); */
		head = head->next;
	}
}
