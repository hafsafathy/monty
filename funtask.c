#include "monty.h"

/**
 * none - Does nothing.
 * @stack: Pointer.
 * @ln_num: number.
 */
void none(stack_t **stack, unsigned int ln_num)
{
	(void)stack;
	(void)ln_num;
}


/**
 * swap_nod - Swaps the top two elements of the stack.
 * @stack: Pointer.
 * @ln_num: number.
 */
void swap_nod(stack_t **stack, unsigned int ln_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		mo_error(8, ln_num, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * add_nod - Adds the top two elements of the stack.
 * @stack: Pointer.
 * @ln_num: number.
 */
void add_nod(stack_t **stack, unsigned int ln_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		mo_error(8, ln_num, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub_nod - Adds the top two elements of the stack.
 * @stack: Pointer.
 * @ln_num: number.
 */
void sub_nod(stack_t **stack, unsigned int ln_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		mo_error(8, ln_num, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_nod - Adds the top two elements of the stack.
 * @stack: Pointer.
 * @ln_num: number.
 */
void div_nod(stack_t **stack, unsigned int ln_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		mo_error(8, ln_num, "div");

	if ((*stack)->n == 0)
		mo_error(9, ln_num);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
