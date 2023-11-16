#include "monty.h"
global_var var_global;
/**
 * main - the entry point
 * @ac: int num of arguments count
 * @av: opcode file list
 * Return: 0
 */
int main(int ac, char **av)
{
	stack_t *stack;

	stack = NULL;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(av[1], &stack);
    /* recordar liberar memorias */
	free_dlistint(stack);
	return (0);
}
