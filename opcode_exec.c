#include "monty.h"

/**
 * opcode_exec - finds the right oprator to do for opcode
 * @instruction: the instruction
 * @head: the head of the linked list
 *
 * Return: function to operator
 */

void opcode_exec(char **instruction, int line_number, stack_t **head)
{
	int i;
	instruction_t op_function[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	char *op_test[] = {"push", NULL};
	char *op_int;
	char *num;

	op_int = instruction[0];

	if (instruction[1])
		num = instruction[1];

	for (i = 0; op_test[i] != NULL; i++)
	{
		if (strcmp(op_test[i], op_int) == 0)
		{
			if (instruction[1] == NULL || isInteger(num))
				error_handler(106, NULL, line_number);
		}
	}

	if (num != NULL)
		stack_number = atoi(num);
	for (i = 0; op_function[i].opcode != NULL; i++)
	{
		if (strcmp(op_function[i].opcode, op_int) == 0)
		{
			op_function[i].f(head, line_number);
			break;
		}
	}
}
