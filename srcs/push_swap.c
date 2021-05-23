#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (!check_args(argc, argv))
		print_and_exit("Problem with args", 1);
	stack = get_stack_from_args(argc, argv);

	//print_stacks(stack, NULL);

	stack = sort(stack, STACK_A);

	//print_stacks(stack, NULL);
	//if (is_sorted(stack))
	//	printf("[OK!]\n");
	//TODO: remove print_stacks.c file and all printfs
	//TODO: norminette push_swap.h
	free(stack);
	return (0);
}
