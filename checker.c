#include "checker.h"

int	main(int argc, char **argv)
{
	char	*line;
	t_stack	*a;
	t_stack	*b;

	if (!check_args(argc, argv))
		exit(1);
	a = get_stack_from_args(argc, argv);
	b = NULL;
	print_stacks(a, b);
	while (get_next_line(0, &line))
	{
		if (!run_command(&a, &b, line))
			print_and_exit("Error running command", 86);
		print_stacks(a, b);
		if (is_sorted(a, b))
			break ;
	}
	return (1);
}
