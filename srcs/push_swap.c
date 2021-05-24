#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (!check_args(argc, argv))
	{
		ft_putstr_fd("Error\n", 1);
		exit(1);
	}
	stack = get_stack_from_args(argc, argv);
	stack = sort(stack, STACK_A);
	free(stack);
	return (0);
}
