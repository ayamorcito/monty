#include "monty.h"

void push_func(FILE *file, char **elements, char *line, stack_t **head)
{
    int a = 0, n;
    stack_t *new;
    char *element;

    element = elements[1];

    while (element[a] != '\0')
    {
        if (element[a] < '0')
        {
            fclose(file);
        }
    }
    
    if (*head != NULL)
    {
        new->n = n;
        (*head)->prev = new;
        new->prev = NULL;
        new->next = *head;
        *head = new;
    }
    
}