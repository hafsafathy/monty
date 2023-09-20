#include "monty.h"

/**
 * mul_nod - Adds the top two elements of the stack.
 * @stck: Pointer.
 * @ln_number: num.
 */
void mul_nod(stack_t **stck, unsigned int ln_number)
{
	int sum;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)
		mo_error(8, ln_number, "mul");

	(*stck) = (*stck)->next;
	sum = (*stck)->n * (*stck)->prev->n;
	(*stck)->n = sum;
	free((*stck)->prev);
	(*stck)->prev = NULL;
}


/**
 * mod_nod - Adds the top two elements of the stack.
 * @stck: Pointer.
 * @ln_number: Interger.
 */
void mod_nod(stack_t **stck, unsigned int ln_number)
{
	int sum;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)

		mo_error(8, ln_number, "mod");


	if ((*stck)->n == 0)
		mo_error(9, ln_number);
	(*stck) = (*stck)->next;
	sum = (*stck)->n % (*stck)->prev->n;
	(*stck)->n = sum;
	free((*stck)->prev);
	(*stck)->prev = NULL;
}
