#include "monty.h"
/**
 * pint - Prints the value at the top of the stack, followed by a new line.
 * @stack: The linear data structure.
 * @line_number: The line number.
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
if (is_stack_empty(*stack))
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
printf("%d\n", (*stack)->n);
}
