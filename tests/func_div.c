#include "monty.h"

/**
 * _pint - print int a top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;
	int aux = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		free(stack);
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		error_exit(stack);
	}
    else
    {
        if ((*stack)->n == 0)
        {
        free(stack);
		fprintf(stderr, "L%u: division by zero\n", line_number);
		error_exit(stack);
        }
        
        free(*stack);
	    aux = runner->next->n / runner->n;
	    runner->n = aux;
	    delete_dnodeint_at_index(stack, 1);

    }
}