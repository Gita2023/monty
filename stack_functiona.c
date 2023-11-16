#include "monty.h"


/**
 * pushToStack - Adds a node to the stack.
 * @newNode: Pointer to the new node.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void pushToStack(stack_t **newNode, __attribute__((unused))unsigned int lineNumber)
{
	stack_t *tmp;

	if (newNode == NULL || *newNode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newNode;
		return;
	}
	tmp = head;
	head = *newNode;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * printStackNodes - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Line number of the opcode.
 */
void printStackNodes(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * popStackTop - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void popStackTop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * printTopNode - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void printTopNode(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}
