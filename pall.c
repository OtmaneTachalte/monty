/**
 * pall - prints all the values on the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number in the script, unused
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number; /* unused parameter */

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
