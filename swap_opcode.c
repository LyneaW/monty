#include "monty.h"
/**
 * swap - The opcode swap swaps the top two elements of the stack.
 * @stack: Linear data structure.
 * @line_number: The line number.
 * Return: Nothing.
 */

void swap(stack_t **stack, unsigned int line_number)
{
int temp = (*stack)->n;
if (empty_stack(*stack) || !(*stack)->next)
{
fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
(*stack)->n = (*stack)->next->n;
(*stack)->next->n = temp;
}
