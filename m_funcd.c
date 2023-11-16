#include "monty.h"

/**
 * _pstr - Prints a string
 * @stack: Ahead to a pointer pointing to top node of the stack.
 * @line_number: numbers representing the line number of the opcode.
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int c = 0;

	(void)line_number;


	while (tmp)
	{
		c = tmp->n;
		if (c == 0 || _isalpha(c) == 0)
			break;
		putchar(c);
		tmp = tmp->next;
	}
	putchar('\n');
}

/**
 * _rotl - Rotates the first node of the stack to the bottom.
 * @stack: Ahead to a pointer pointing to top node of the stack.
 * @line_number: numbers representing the line number of the opcode.
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;


	int axis = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	axis = runner->n;

	while (runner->next)
	{
		runner = runner->next;
		runner->prev->n = runner->n;
	}

	runner->n = axis;
}

/**
 * _rotr - Rotates the last node of the stack to the top
 * @stack: Ahead to a pointer pointing to top node of the stack.
 * @line_number: numbers representing the line number of the opcode.
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;

	int axis = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	while (runner->next)
		runner = runner->next;

	axis = runner->n;

	while (runner->prev)
	{
		runner = runner->prev;
		runner->next->n = runner->n;
	}

	runner->n = axis;
}
