#include "monty.h"

/**
 * opn_file - opens a file
 * @f_name: file name
 * Return: void
 */

void opn_file(char *f_name)
{
	FILE *fd = fopen(f_name, "r");

	if (f_name == NULL || fd == NULL)
		error(2, f_name);

	rd_file(fd);
	fclose(fd);
}


/**
 * rd_file - reads a file
 * @fd: pointer.
 * Return: void.
 */

void rd_file(FILE *fd)
{
	int ln_number, format = 0;
	char *buffer = NULL;
	size_t l = 0;

	for (ln_number = 1; getline(&buffer, &l, fd) != -1; ln_number++)
	{
		format = par_line(buffer, ln_number, format);
	}
	free(buffer);
}


/**
 * par_line - Separates line into tokens to call right func.
 * @buffer: line from the file
 * @ln_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int par_line(char *buffer, int ln_number, int format)
{
	char *opcode, *value;
	const char *delm = "\n ";

	if (buffer == NULL)
		error(4);

	opcode = strtok(buffer, delm);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delm);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	fd_fun(opcode, value, ln_number, format);
	return (format);
}

/**
 * fd_fun - find the fun
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln_num: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void fd_fun(char *opcode, char *value, int ln_num, int format)
{
	int i;
	int flg;

	instruction_t fun_list[] = {
		{"push", ad_tosk},
		{"pall", pr_stck},
		{"pint", pr_top},
		{"pop", p_top},
		{"nop", none},
		{"swap", swap_nod},
		{"add", add_nod},
		{"sub", sub_nod},
		{"div", div_nod},
		{"mul", mul_nod},
		{"mod", mod_nod},
		{"pchar", p_char},
		{"pstr", pr_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flg = 1, i = 0; fun_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, fun_list[i].opcode) == 0)
		{
			c_fun(fun_list[i].f, opcode, value, ln_num, format);
			flg = 0;
		}
	}
	if (flg == 1)
		error(3, ln_num, opcode);
}


/**
 * c_fun - Calls the required function.
 * @funs: Pointer.
 * @op: string representing the opcode.
 * @value: string.
 * @ln_num: line numeber.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void c_fun(op_Fun funs, char *op, char *value, int ln_num, int format)
{
	stack_t *noder;
	int flg;
	int i;

	flg = 1;
	if (strcmp(op, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			flg = -1;
		}
		if (value == NULL)
			error(5, ln_num);
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
				error(5, ln_num);
		}
		noder = crt_node(atoi(value) * flg);
		if (format == 0)
			funs(&noder, ln_num);
		if (format == 1)
			ad_toqu(&noder, ln_num);
	}
	else
		funs(&header, ln_num);
}
