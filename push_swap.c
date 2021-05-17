#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;
	size_t	size;

	if (!check_args(argc, argv))
		print_and_exit("Problem with args", 1);
	stack = get_stack_from_args(argc, argv);
	size = stack_size(stack);

//	print_stacks(stack, NULL);
//	ft_putstr_fd("-------------\n", 1);
	if (size == 2)
		stack = sort_2(stack, STACK_A);
	if (size == 3)
		stack = sort_3(stack, STACK_A);
	else if (size == 5)
		stack = sort_5(stack, STACK_A);
//	else if (size == 100)
//		sort_top_100(stack, STACK_A);
//	else if (size == 500)
//		sort_top_500(stack, STACK_A);
//	else
//		sort_generic(stack, STACK_A);
//	print_stacks(stack, NULL);
//	if (is_sorted(stack))
//		ft_putstr_fd("Ayyyyy\n", 1);
//	else
//		ft_putstr_fd("bruh\n", 1);
	return (0);
}
