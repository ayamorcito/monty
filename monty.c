#include "monty.h"

void main(char **filename, stack_t **stack, **elements)
{
	char *buffer = NULL;
	char *line;
	size_t i = 0;
	int check;
	int read = 0;
	FILE *file; 

	file = fopen("06.m", "r");

	if (file == NULL)
	{
		printf("Error: Can't open file");
		return;
	}

	while ((read = getline(&buffer, &i, file)) != '\0')
	{
		printf("%i\n", read);
		return;
	}
}
