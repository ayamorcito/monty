#include "monty.h"

/**
 * _pint - print int a top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;
	int aux = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		error_exit(stack);
	}

	if (aux < 0)
	{
		printf("es negativo");
	}

	aux = runner->n - runner->next->n;
	runner->n = aux;
	delete_dnodeint_at_index(stack, 1);

}