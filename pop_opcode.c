#include "monty.h"
/**
 * pop - The opcode pop removes the top element of the stack.
 * @stack: The linear data structure.
 * @line_number: The line number.
 * Return: Nothing.
 */
void pop(stack_t **stack, unsigned int line_number)
{
stack_t *temp = *stack;

if (is_stack_empty(*stack))
{
fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}

*stack = (*stack)->next;

if (*stack)
(*stack)->prev = NULL;

free(temp);
}
