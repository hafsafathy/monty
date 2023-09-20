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
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *header;
typedef void (*op_Fun)(stack_t **, unsigned int);


void opn_file(char *f_name);
int par_line(char *buffer, int ln_number, int format);
void rd_file(FILE *);
int l_char(FILE *);
void fd_fun(char *, char *, int, int);


stack_t *crt_node(int n);
void fre_node(void);
void pr_stck(stack_t **, unsigned int);
void ad_tosk(stack_t **, unsigned int);
void ad_toqu(stack_t **, unsigned int);

void c_fun(op_Fun, char *, char *, int, int);

void pr_top(stack_t **, unsigned int);
void p_top(stack_t **, unsigned int);
void none(stack_t **, unsigned int);
void swap_nod(stack_t **, unsigned int);


void add_nod(stack_t **, unsigned int);
void sub_nod(stack_t **, unsigned int);
void div_nod(stack_t **, unsigned int);
void mul_nod(stack_t **, unsigned int);
void mod_nod(stack_t **, unsigned int);


void p_char(stack_t **, unsigned int);
void pr_str(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);


void error(int err_code, ...);
void mo_error(int error_code, ...);
void str_error(int error_code, ...);
void rotr(stack_t **, unsigned int);

#endif
