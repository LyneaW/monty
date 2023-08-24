#include "monty.h"
/**
 * handles_opcodes- Code that handles the opcodes.
 * @opcode: The OPCODE.
 * @arg: The Argument.
 * @stack: The linear data structure.
 * @line_number: The line number.
 * Return: Void.
 */
void handles_opcodes(char *opcode, char *arg, stack_t **stack, unsigned int line_number)
{
int val;
if (strcmp(opcode, "push") == 0)
{
if (!arg || !is_integer(arg))
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
stacks(stack);
exit(EXIT_FAILURE);
}
val = atoi(arg);
push(stack, line_number, val);
}
else if (opcode && strcmp(opcode, "pall") == 0)
pall(stack, line_number);
else if (opcode && strcmp(opcode, "pint") == 0)
pint(stack, line_number);
else if (opcode && strcmp(opcode, "pop") == 0)
pop(stack, line_number);
else if (opcode && strcmp(opcode, "swap") == 0)
swap(stack, line_number);
else if (opcode && strcmp(opcode, "add") == 0)
add(stack, line_number);
else if (opcode && strcmp(opcode, "nop") == 0)
nop(stack, line_number);
else
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
stacks(stack);
exit(EXIT_FAILURE);
}
}
