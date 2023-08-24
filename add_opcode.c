#include "monty.h"
/**
 * add - the opcode adds the top two elements of the stack
 * @stack: The linear  data structure.
 * @line_number: The line number.
 * Return: Void.
 */

void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
