#include "monty.h"
stack_t *header = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	opn_file(argv[1]);
	fre_node();
	return (0);
}

/**
 * crt_node - Creates a node.
 * @n: Number.
 * Return: node in sucess Otherwise NULL.
 */
stack_t *crt_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		error(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * fre_node - Frees nodes in the stack.
 */
void fre_node(void)
{
	stack_t *t;

	if (header == NULL)
		return;

	while (header != NULL)
	{
		t = header;
		header = header->next;
		free(t);
	}
}


/**
 * ad_toqu - Adds a node to the queue.
 * @new_node: Pointer.
 * @ln: line number.
 */
void ad_toqu(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *t;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (header == NULL)
	{
		header = *new_node;
		return;
	}
	t = header;
	while (t->next != NULL)
		t = t->next;

	t->next = *new_node;
	(*new_node)->prev = t;

}
