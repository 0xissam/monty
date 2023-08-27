#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * struct stack_s - doubly linked  ertetik uiodg list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the uiudjfd dfgd previous element of the stack (or queue)
 * @next: points to the sdhfsiu sdfui next element of the stack (or queue)
 *
 * Description: doubly uhsdfi linked list node structure
 * for stack, queues,uuxui LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - hsdfhiuopcode and its function
 * @opcode: the opcodecc
 * @f: function to handlehhsdfiu the opcode
 *
 * Description: opcode anduhsdf its function
 * for stack, queuesifso, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct data - alluhsdfius data in program
 * @push_value: value ioksdf uihsdfto push
 * @line_num: line numberuhdfi sdf of opcode
 * @opcode: the opcodeijdf sdfij
 * @mfile: file to openiojdsf
 * @top: the top of stackoskpf
 * @mode: 0 mean stack, 1 meanjiodsf queue
 * in stack you push in the isfdo start
 * in the queue sdfsf
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

/*functions.c*/
FILE *openfile(char *filename);
size_t num_len(int num);
void verify_number(char *token);
void free_stack(stack_t *top);

/*opcodes.c*/
void _push(stack_t **top, unsigned int line_number);
void _pall(stack_t **top, unsigned int line_number);
void _pint(stack_t **top, unsigned int line_number);
void _nop(stack_t **top, unsigned int line_number);
void _sub(stack_t **top, unsigned int line_number);
void _pop(stack_t **top, unsigned int line_number);
void _swap(stack_t **top, unsigned int line_number);
void _pchar(stack_t **top, unsigned int line_number);
void _pstr(stack_t **top, unsigned int line_number);
void _rotl(stack_t **top, unsigned int line_number);
void _rotr(stack_t **top, unsigned int line_number);
void _mode(stack_t **top, unsigned int line_number);
void _add(stack_t **top, unsigned int line_number);
void _div(stack_t **top, unsigned int line_number);
void _mul(stack_t **top, unsigned int line_number);
void _mod(stack_t **top, unsigned int line_number);

/*main.c*/
void exec(void);
int main(int argc, char **argv);

#endif
