#include "monty.h"
/**
 * _push - push int to a stack
 * @stack: linked lists for stack
 * @ln: number of line opcode work on
 */
void _push(stack_t **stack, __attribute__ ((unused))unsigned int ln)
{
	stack_t *top;
	(void)ln;

	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	top->n = var_global.push_arg;
	top->next = *stack;
	top->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = top;
	*stack = top;
}

/**
 * _pall - print all function
 * @stack: Ahead to linked list stack
 * @ln: number of line opcode work on
 */
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int ln)
{
	stack_t *runner;

	runner = *stack;
	while (runner != NULL)
	{
		printf("%d\n", runner->n);
		runner = runner->next;
	}
}

/**
 * _pint - print int a top of stack
 * @stack: Ahead to linked list stack
 * @ln: number of line opcode work on
 *
 */
void _pint(stack_t **stack, unsigned int ln)
{
	stack_t *runner;

	runner = *stack;
	if (runner == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", runner->n);
}

/**
 * _pop - remove element a list
 *@stack: Ahead to first node
 *@ln: integer
 *Return: void
 */
void _pop(stack_t **stack, unsigned int ln)
{
	stack_t *nodo = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
		exit(EXIT_FAILURE);
	}
	*stack = nodo->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(nodo);
}

/**
 * free_dlistint - free a list
 * @head: Ahead to first node
 *
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

