#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>

/**
 * struct data - all data
 * @push_value: value to push
 * @line_num: line num for opcode
 * @opcode: the opcode
 * @mfile: file to open
 * @top: top of stack
 * @mode: 0 mean stack, 1 mean queue
 * in stack you push in the start
 * in the queue you push at end
 */
typedef struct data
{
	int push_value;
	unsigned int line_num;
	char *opcode;
	FILE *mfile;
	stack_t *top;
	int mode;
} data;
data datax;

/**
 * struct stk - doubly linked list representation of a stack
 * @n: integer
 * @prev: points to the previous element of the stack
 * @next: points to the next element of the stack
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stk
{
	int n;
	struct stk *prev;
	struct stk *next;
} stack_t;

/**
 * struct opc - opcode and function
 * @opcode: the opcode
 * @f: function for handling the opcode
 *
 * Description: opcode and function
 * for stack, queues, LIFO, FIFO
 */
typedef struct opc
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int l_num);
} instruction_t;


/*helpers.c*/
FILE *openf(char *filename);
size_t conter(int num);
void verify_n(char *token);
void free_st(stack_t *top);

/*opcodes.c*/
void _n_node(stack_t **top, unsigned int l_num);
void _pstr(stack_t **top, unsigned int l_num);
void _rott(stack_t **top, unsigned int l_num);
void _printer(stack_t **top, unsigned int l_num);
void _print_tofs(stack_t **top, unsigned int l_num);
void _rm_tofs(stack_t **top, unsigned int l_num);
void _rotb(stack_t **top, unsigned int l_num);
void _swap(stack_t **top, unsigned int l_num);
void _add(stack_t **top, unsigned int l_num);
void _div(stack_t **top, unsigned int l_num);
void _mul(stack_t **top, unsigned int l_num);
void _mod(stack_t **top, unsigned int l_num);
void _nothing(stack_t **top, unsigned int l_num);
void _sub(stack_t **top, unsigned int l_num);
void _pchar(stack_t **top, unsigned int l_num);
void _mode_switch(stack_t **top, unsigned int l_num);

/*main.c*/
void exec(void);
int main(int argc, char **argv);


#endif
