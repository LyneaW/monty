#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>

#define MAXIMUM_LENGTH_OF_LINE 1024
#define USAGE "USAGE: monty file\n"
#define ERROR_OPEN "Error: Can't open file %s\n"
#define ERROR_UNKNOWN "L%u: unknown instruction %s\n"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*Declaration of functions*/
int is_integer(const char *str);
int main(int argc, char *argv[]);
void pop(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number, int value);
void swap(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
int empty_stack(stack_t *stack);
void stacks(stack_t **stack);
void handles_opcodes(char *opcode, char *arg, stack_t **stack, unsigned int line_number);
void check_for_arguments(int argc);
FILE *open_file(const char *path_of_file);
#endif /* MONTY_H */
