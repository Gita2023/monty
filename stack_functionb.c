#include "monty.h"

/**
 * doNothing - Does nothing.
 * @currentStack: Ahead to a Ahead pointing to the top node of the currentStack.
 * @lineNumber: Integer representing the line number of the operation code.
 */
void doNothing(stack_t **currentStack, unsigned int lineNum)
{
	(void)currentStack;
	(void)lineNum;
}


/**
 * swapStackNodes - Swaps the top two elements of the currentStack.
 * @currentStack: Ahead to a Ahead pointing to top node of the currentStack.
 * @lineNum: Interger representing the line number of of the opcode.
 */
void swapStackNodes(stack_t **currentStack, unsigned int lineNum)
{
	stack_t *tmp;

	if (currentStack == NULL || *currentStack == NULL || (*currentStack)->next == NULL)
		more_err(8, lineNum, "swap");
	tmp = (*currentStack)->next;
	(*currentStack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *currentStack;
	tmp->next = *currentStack;
	(*currentStack)->prev = tmp;
	tmp->prev = NULL;
	*currentStack = tmp;
}

/**
 * addStackNodes - Adds the top two elements of the currentStack.
 * @currentStack: Ahead to a Ahead pointing to top node of the currentStack.
 * @lineNum: Interger representing the line number of of the opcode.
 */
void addStackNodes(stack_t **currentStack, unsigned int lineNum)
{
	int sum;

	if (currentStack == NULL || *currentStack == NULL || (*currentStack)->next == NULL)
		more_err(8, lineNum, "add");

	(*currentStack) = (*currentStack)->next;
	sum = (*currentStack)->n + (*currentStack)->prev->n;
	(*currentStack)->n = sum;
	free((*currentStack)->prev);
	(*currentStack)->prev = NULL;
}


/**
 * subStackNodes - Adds the top two elements of the currentStack.
 * @currentStack: Ahead to a Ahead pointing to top node of the currentStack.
 * @lineNum: Interger representing the line number of of the opcode.
 */
void subStackNodes(stack_t **currentStack, unsigned int lineNum)
{
	int sum;

	if (currentStack == NULL || *currentStack == NULL || (*currentStack)->next == NULL)

		more_err(8, lineNum, "sub");


	(*currentStack) = (*currentStack)->next;
	sum = (*currentStack)->n - (*currentStack)->prev->n;
	(*currentStack)->n = sum;
	free((*currentStack)->prev);
	(*currentStack)->prev = NULL;
}


/**
 * divStackNodes - Adds the top two elements of the currentStack.
 * @currentStack: Ahead to a Ahead pointing to top node of the currentStack.
 * @lineNum: Interger representing the line number of of the opcode.
 */
void divStackNodes(stack_t **currentStack, unsigned int lineNum)
{
	int sum;

	if (currentStack == NULL || *currentStack == NULL || (*currentStack)->next == NULL)
		more_err(8, lineNum, "div");

	if ((*currentStack)->n == 0)
		more_err(9, lineNum);
	(*currentStack) = (*currentStack)->next;
	sum = (*currentStack)->n / (*currentStack)->prev->n;
	(*currentStack)->n = sum;
	free((*currentStack)->prev);
	(*currentStack)->prev = NULL;
}
