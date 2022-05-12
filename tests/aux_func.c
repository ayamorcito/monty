#include "monty.h"

/**
 * isnumber - checks if a string is a number
 * @str: string being passed
 *
 * Return: returns 1 if string is a number, 0 otherwise
 */
int isnumber(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);
	i = 0;

	if (str[0] == '-')
		i++;

	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			i++;
		
		else
			return (0);
	}
	return (1);
}


/**
 * error_exit - frees the stack and exits due to erro
 * @stack: pointer to the head of the stack
 *
 */
void error_exit(stack_t **stack)
{
	if (*stack)
		free_stack(*stack);

	exit(EXIT_FAILURE);
}
