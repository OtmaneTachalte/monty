#include "monty.h"

/**
 * main - Entry point for the Monty bytecode interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments, including the Monty file path
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	bus_t bus = {NULL, NULL, NULL, 0};
	char *line_content;
	FILE *monty_file;
	size_t line_size = 0;
	ssize_t line_read = 1;
	stack_t *stack = NULL;
	unsigned int line_counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	monty_file = fopen(argv[1], "r");
	bus.file = monty_file;
	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (line_read > 0)
	{
		line_content = NULL;
		line_read = getline(&line_content, &line_size, monty_file);
		bus.content = line_content;
		line_counter++;
		if (line_read > 0)
		{
			execute_opcode(&bus, &stack, line_counter);
		}
		free(line_content);
	}

	free_stack(stack);
	fclose(monty_file);
	return (0);
}
