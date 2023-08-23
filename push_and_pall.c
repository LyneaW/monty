#include "monty.h"
/**
 * push- Pushes an element to the stack.
 * @stack : The linear data structure.
 * @line_number: The line number.
 * @value: The value to be inserted.
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number, int value)
{
stack_t *new_node = malloc(sizeof(stack_t));

(void)line_number;
if (!new_node)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = value;
new_node->prev = NULL;
new_node->next = *stack;

if (*stack)
(*stack)->prev = new_node;
*stack = new_node;
}

/**
 * pall- Prints all the values on the stack, starting from the top of the stack.
 * @stack: The linear data structure.
 * @line_number: The line number.
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *current = *stack;
(void)line_number;

while (current)
{
printf("%d\n", current->n);
current = current->next;
}
}
