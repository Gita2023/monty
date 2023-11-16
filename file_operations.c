#include "monty.h"

/**
 * openMontyFile - Opens a Monty file.
 * @fileName: The file path.
 * Return: void
 */

void openMontyFile(char *file_name)
{
	FILE *Fdescriptor = fopen(file_name, "r");

	if (file_name == NULL || Fdescriptor == NULL)
		handleError(2, file_name);

	readMontyFile(Fdescriptor);
	fclose(Fdescriptor);
}


/**
 * readMontyFile - Reads a Monty file.
 * @fd: Pointer to file descriptor.
 * Return: void
 */

void readMontyFile(FILE *Fdescriptor)
{
	int line_number, Sformat = 0;
	char *inputBuffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&inputBuffer, &len, Fdescriptor) != -1; line_number++)
	{
		Sformat = parseMontyLine(inputBuffer, line_number, Sformat);
	}
	free(inputBuffer);
}


/**
 * parseMontyLine - Separates each line into tokens to determine it to,
   which function to call
 * @inputBuffer: line from the file
 * @line_number: line number
 * @Sformat:  storage Sformat. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the operation is stack. 1 if queue.
 */

int parseMontyLine(char *inputBuffer, int line_number, int Sformat)
{
	char *operation, *argument;
	const char *delimiter = "\n ";

	if (inputBuffer == NULL)
		handleError(4);

	operation = strtok(inputBuffer, delimiter);
	if (operation == NULL)
		return (Sformat);
	argument = strtok(NULL, delimiter);

	if (strcmp(operation, "stack") == 0)
		return (0);
	if (strcmp(operation, "queue") == 0)
		return (1);

	findMontyFunction(operation, argument, line_number, Sformat);
	return (Sformat);
}

/**
 * findMontyFunction - Find the appropriate function for the opcode.
 * @opcode: Opcode.
 * @value: Argument of opcode.
 * @lineNumber: Line number.
 * @format: Storage format. If 0, Nodes will be entered as a stack.
 *          If 1, nodes will be entered as a queue.
 * Return: void
 */
void findMontyFunction(char *operation, char *argument, int lineNumber, int Sformat)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (operation[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].operation != NULL; i++)
	{
		if (strcmp(operation, func_list[i].operation) == 0)
		{
			call_fun(func_list[i].f, operation, argument, lineNumber, Sformat);
			flag = 0;
		}
	}
	if (flag == 1)
		handleError(3, lineNumber, operation);
}


/**
 * callMontyFunction - Calls the required function.
 * @operationFunc: Ahead to the function that is about to be called.
 * @operation: String representing the operation code.
 * @value: String representing a numeric value.
 * @lineNumber: Line number for the instruction.
 * @format: Format specifier. If 0, Nodes will be entered as a stack.
 *          If 1, nodes will be entered as a queue.
 */
void callMontyFunction(op_func operationFunc, char *operation, char *value, int lineNumber, int Sformat)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(operation, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			flag = -1;
		}
		if (value == NULL)
			handleError(5, lineNumber);
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
				handleError(5, lineNumber);
		}
		node = create_node(atoi(value) * flag);
		if (Sformat == 0)
			operationFunc(&node, lineNumber);
		if (Sformat == 1)
			add_to_queue(&node, lineNumber);
	}
	else
		operationFunc(&head, lineNumber);
}
