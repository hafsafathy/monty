#include "monty.h"


/**
 * ad_tosk - Adds a node to the stack.
 * @new_node: Pointer.
 * @ln_num: number.
 */
void ad_tosk(stack_t **new_node, __attribute__((unused))unsigned int ln_num)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (header == NULL)
	{
		header = *new_node;
		return;
	}
	tmp = header;
	header = *new_node;
	header->next = tmp;
	tmp->prev = header;
}


/**
 * pr_stck - Adds a node to the stack.
 * @stack: Pointer.
 * @ln_num: number.
 */
void pr_stck(stack_t **stack, unsigned int ln_num)
{
	stack_t *tmp;

	(void) ln_num;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * p_top - Adds a node to the stack.
 * @stack: Pointer.
 * @ln_num: number.
 */
void p_top(stack_t **stack, unsigned int ln_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		mo_error(7, ln_num);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * pr_top - Prints the top node of the stack.
 * @stack: Pointer.
 * @ln_num: number.
 */
void pr_top(stack_t **stack, unsigned int ln_num)
{
	if (stack == NULL || *stack == NULL)
		mo_error(6, ln_num);
	printf("%d\n", (*stack)->n);
}
