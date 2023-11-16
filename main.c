#include "monty.h"
stack_t *globalHead = NULL;

/**
 * main - entry point
 * @argumentCount: arguments count
 * @argumentValues: list of arguments
 * Return: always 0
 */

int main(int argumentCount, char *argumentValues[])
{
	if (argumentCount != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argumentValues[1]);
	freeStackNodes();
	return (0);
}

/**
 * createStackNode - Creates a stack node.
 * @value: Number to be stored in the node
 * Return: A pointer to the newly created stack node
 */
stack_t *createStackNode(int value)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		handleError(4);
	node->next = NULL;
	node->prev = NULL;
	node->value = value;
	return (node);
}

/**
 * freeStackNodes - Frees all nodes in the stack.
 */
void freeStackNodes(void)
{
	stack_t *tempNode;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tempNode = head;
		head = head->next;
		free(tempNode);
	}
}


/**
 * enqueue - Adds a node to the queue.
 * @newNode: Pointer to the new node to be added
 * @lineNumber: Line number of the opcode
 */
void enqueue(stack_t **newNode, __attribute__((unused))unsigned int lineNumber)
{
	stack_t *tempNode;

	if (newNode == NULL || *newNode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newNode;
		return;
	}
	tempNode = head;
	while (tempNode->next != NULL)
		tempNode = tempNode->next;

	tempNode->next = *newNode;
	(*newNode)->prev = tempNode;

}
