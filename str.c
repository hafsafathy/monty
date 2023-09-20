#include "monty.h"

/**
 * p_char - Prints the Ascii value.
 * @stck: Pointer.
 * @ln_number: num.
 */
void p_char(stack_t **stck, unsigned int ln_number)
{
	int ascii;

	if (stck == NULL || *stck == NULL)
		str_error(11, ln_number);

	ascii = (*stck)->n;
	if (ascii < 0 || ascii > 127)
		str_error(10, ln_number);
	printf("%c\n", ascii);
}

/**
 * pr_str - Prints a string.
 * @stck: Pointer.
 * @ln_num: number.
 */
void pr_str(stack_t **stck, __attribute__((unused))unsigned int ln_num)
{
	int ascii;
	stack_t *tmp;

	if (stck == NULL || *stck == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stck;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stck: Pointer.
 * @ln_num: num.
 */
void rotl(stack_t **stck, __attribute__((unused))unsigned int ln_num)
{
	stack_t *tmp;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)
		return;

	tmp = *stck;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stck;
	(*stck)->prev = tmp;
	*stck = (*stck)->next;
	(*stck)->prev->next = NULL;
	(*stck)->prev = NULL;
}


/**
 * rotr - Rotates the last node of the stack to the top.
 * @stck: Pointer.
 * @ln_num: num.
 */
void rotr(stack_t **stck, __attribute__((unused))unsigned int ln_num)
{
	stack_t *tmp;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)
		return;

	tmp = *stck;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stck;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stck)->prev = tmp;
	(*stck) = tmp;
}
