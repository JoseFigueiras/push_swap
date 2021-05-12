#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (!check_args(argc, argv))
		print_and_exit("Problem with args", 1);
	a = get_stack_from_args(argc, argv);
	b = NULL;
}
