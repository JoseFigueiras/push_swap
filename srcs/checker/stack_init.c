#include "checker.c"

static t_stack	*stack_new(int item);

t_stack	*stack_init(int *items, size_t size)
{
	size_t	i;
	t_stack	*stack;
	t_stack *current;

	stack = stack_new(items[0]);
	current = stack;
	i = 1;
	while (i < size)
	{
		current->next = stack_new(items[i]);
		if (!current->next)
			exit(15);
		current->next->prev = current;
		current = current->next;
		i++;
	}
	return (stack);
}

static t_stack	*stack_new(int item)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->item = item;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
