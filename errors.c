#include "monty.h"

/**
 * error - Prints appropiate error messages determined by their error code.
 * @err_code: The error codes are the following:
 * (1) => not give any file or more than one file to the program.
 * (2) => provided is not a file that can be opened or read.
 * (3) => provided contains an invalid instruction.
 * (4) => unable to malloc more memory.
 * (5) => parameter passed to the instruction "push" is not an int.
 * (6) => stack it empty for pint.
 * (7) => stack it empty for pop.
 * (8) => stack is too short for operation.
 */
void error(int err_code, ...)
{
	va_list ag;
	char *op;
	int ln_num;

	va_start(ag, err_code);
	switch (err_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			ln_num = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", ln_num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	fre_node();
	exit(EXIT_FAILURE);
}

/**
 * mo_error - handles errors.
 * @err_code: The error codes are the following:
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 * (9) => Division by zero.
 */
void mo_error(int err_code, ...)
{
	va_list ag;
	char *op;
	int ln_num;

	va_start(ag, err_code);
	switch (err_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			ln_num = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", ln_num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	fre_node();
	exit(EXIT_FAILURE);
}

/**
 * str_error - handles errors.
 * @err_code: The error codes are the following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void str_error(int err_code, ...)
{
	va_list ag;
	int ln_num;

	va_start(ag, err_code);
	ln_num = va_arg(ag, int);
	switch (err_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", ln_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", ln_num);
			break;
		default:
			break;
	}
	fre_node();
	exit(EXIT_FAILURE);
}
