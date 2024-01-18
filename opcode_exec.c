#include "monty.h"

/**
 * opcode_exec - finds the right oprator to do for opcode
 * @instruction: the instruction
 *
 * Return: function to operator
 */

void opcode_exec(char **instruction, int line_number)
{
	int i;
	instruction_t **op_function = {
		{"push", push},
		{"pall", pall},
		{"NULL", "NULL"}
	};
	char *op_test[] = {"push", NULL};
	char *op_int;
	char *num;
	stack_t *head = NULL;

	op_int = instruction[0];
	num = instruction[1];
	for (i = 0; op_test[i] != NULL; i++)
	{
		if (strcmp(op_test[i], op_int) == 0)
		{
			if (instruction[1] == NULL || isInteger(num))
				error_handler(106, NULL, line_number);
		}
	}
	for (i = 0; op_function[i] != NULL; i++)
	{
		if (strcmp(op_function[i][0], op_int) == 0)
		{
			op_function[i][1](&head, line_number);
		}
	}
}
