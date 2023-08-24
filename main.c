#include "monty.h"
/**
 * empty_stack- Confirms if the stack is empty.
 * @stack: The stack to be checked.
 * Return: Integer.
 */
int empty_stack(stack_t *stack)
{
return (stack == NULL);
}

/**
 * main- The main code.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: Integer.
 */
int main(int argc, char *argv[])
{
FILE *file;
char line[MAXIMUM_LENGTH_OF_LINE], *opcode, *arg;
unsigned int line_number = 1;
stack_t *stack = NULL;
check_for_arguments(argc);
file = open_file(argv[1]);
while (fgets(line, MAXIMUM_LENGTH_OF_LINE, file) != NULL)
{
opcode = strtok(line, " \t\n");
arg = strtok(NULL, " \t\n");
handles_opcodes(opcode, arg, &stack, line_number);
line_number++;
}
fclose(file);
stacks(&stack);
exit(EXIT_SUCCESS);
}

/**
 * stacks- The stack.
 * @stack: The linear data structure.
 * Return: Void.
 */
void stacks(stack_t **stack)
{
stack_t *current = *stack;
stack_t *next;

while (current)
{
next = current->next;
free(current);
current = next;
}
*stack = NULL;
}

/**
 * open_file- Function.
 * @path_of_file: The path of the file.
 * Return: File.
 */
FILE *open_file(const char *path_of_file)
{
FILE *file = fopen(path_of_file, "r");
if (!file)
{
fprintf(stderr, "Error: Can't open file %s\n", path_of_file);
exit(EXIT_FAILURE);
}
return (file);
}

/**
 * check_for_arguments- It helps in checking for arguments.
 * @argc: Argument count.
 * Return: Void.
 */
void check_for_arguments(int argc)
{
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
}
