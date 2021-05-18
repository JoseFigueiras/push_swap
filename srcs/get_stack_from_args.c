#include "push_swap.h"

static t_stack	*stack_init(int *items, size_t size);
static t_stack	*stack_new(int item);

t_stack	*get_stack_from_args(int argc, char **argv)
{
	t_stack	*stack;
	int		list_size;
	int		*list;
	int		i;

	list_size = argc - 1;
	list = malloc(list_size * sizeof(int));
	i = 0;
	while (i < list_size)
	{
		list[i] = ft_atoi(argv[list_size - i]);
		i++;
	}
	stack = stack_init(list, list_size);
	return (stack);
}

static t_stack	*stack_init(int *items, size_t size)
{
	size_t	i;
	t_stack	*stack;
	t_stack	*current;

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
