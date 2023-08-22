#include "monty.h"
/**
 * is_integer- Confirms if it's an integer or not.
 * @str: The string.
 *
 * Return: 1 if integer and  0 if not.
 */
int is_integer(const char *str)
{
int b = 0;

if (!str)
return (0);
if (str[0] == '-')
b++;
for (; str[b]; b++)
{
if (str[b] < '0' || str[b] > '9')
return (0);
}
return (1);
}
