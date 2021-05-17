#include "push_swap.h"

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
