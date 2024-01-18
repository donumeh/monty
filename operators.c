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
	stack_t *new_node;
	stack_t *head;
	stack_t *prev;

	new_node = head = prev = NULL;

	head = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		error_handler(102, NULL, 0);

	new_node->n = stack_number;

	if (head == NULL)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		head = new_node;
	}
	else
	{
		new_node->prev = NULL;
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}
	*stack = head;
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

	head = *stack;

	if (stack == NULL)
		return;

	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
