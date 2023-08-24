#include "monty.h"
/**
 * handles_opcodes - handles opcodes
 * @arg: arguments
 * @line_number: Line number
 * @stack: linear data structure
 * @opcode: operation code
 * Return: Void
 */
void handles_opcodes(char *opcode, char *arg, stack_t **stack,
		unsigned int line_number)
{
	if (strcmp(opcode, "push") == 0)
	{
		int value;

		if (is_integer(arg))
		{
			value = atoi(arg);
			push(stack, line_number, value);
		}
		else
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		pop(stack, line_number);
	}
	else if (strcmp(opcode, "add") == 0)
	{
		add(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
