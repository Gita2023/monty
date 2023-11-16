#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct StackNode - Doubly linked list representation of a stack (or queue)
 * @value: Integer value
 * @prev: Points to the previous element of the stack (or queue)
 * @next: Points to the next element of the stack (or queue)
 *
 * Description: Doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct StackNode
{
        int value;
        struct StackNode *prev;
        struct StackNode *next;
} StackNode;

/**
 * struct instruction_x - operations code and its function
 * @opcode: the operations code
 * @f: function to handle the operations code
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_x
{
        char *opcode;
        void (*f)(StackNode **stack, unsigned int line_number);
} instruction_x;

extern StackNode *head;
typedef void (*operation_func)(StackNode **, unsigned int);

/*file operations*/
void open_file(char *file_name);
int parse_line(char *buffer, int line_number, int format);
void read_file(FILE *);
int len_chars(FILE *);
void find_func(char *, char *, int, int);

/*Stack operations*/
StackNode *create_node(int n);
void free_nodes(void);
void print_stack(StackNode **, unsigned int);
void add_to_stack(StackNode **, unsigned int);
void add_to_queue(StackNode **, unsigned int);

void call_fun(operation_func, char *, char *, int, int);

void print_top(StackNode **, unsigned int);
void pop_top(StackNode **, unsigned int);
void nop(StackNode **, unsigned int);
void swap_nodes(StackNode **, unsigned int);

/*Math operations with nodes*/
void add_nodes(StackNode **, unsigned int);
void sub_nodes(StackNode **, unsigned int);
void div_nodes(StackNode **, unsigned int);
void mul_nodes(StackNode **, unsigned int);
void mod_nodes(StackNode **, unsigned int);

/*String operations*/
void print_char(StackNode **, unsigned int);
void print_str(StackNode **, unsigned int);
void rotl(StackNode **, unsigned int);

/*Error hanlding*/
void err(int errorCode, ...);
void more_err(int errorCode, ...);
void string_err(int errorCode, ...);
void rotr(StackNode **, unsigned int);

#endif
