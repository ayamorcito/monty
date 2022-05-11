#include "monty.h"

void opfile(char *filename, stack_t **stack)
{
	char *buffer = NULL;
	char *str;
	size_t i = 0;
	int str_cn = 1;
	instruct_func s;
	int check;
	int read = 0;

	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		return;
	}
	while ((read = getline(&buffer, &i, file)) != -1)
	{
				
		str = strtok(buffer, " \t\n");

		s = func_cheq(str);
		if (s == NULL)
		{
			printf("L%d: unknown instruction %s\n", str_cn, str);
			return;
		}
		s(stack, str_cn);
		str_cn++;
	}
	free(buffer);
	check = fclose(file);
	if (check == -1)
		exit(-1);
}
