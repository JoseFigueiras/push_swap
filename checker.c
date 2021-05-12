#include "checker.h"

int	main(int argc, char **argv)
{
	char	*line;
	t_stack	*a;
	t_stack	*b;
	int		command_count;

	if (!check_args(argc, argv))
		print_and_exit("Problem with args", 1);
	a = get_stack_from_args(argc, argv);
	b = NULL;
	print_stacks(a, b);
	command_count = 0;
	while (!is_sorted(a, b))
	{
		ft_putstr_fd("\nExec: ", 1);
		get_next_line(0, &line);
		command_count++;
		if (!run_command(&a, &b, line))
			print_and_exit("Error running command", 86);
		ft_putstr_fd("command count: ", 1);
		ft_putnbr_fd(command_count, 1);
		ft_putchar_fd('\n', 1);
		ft_putchar_fd('\n', 1);
		print_stacks(a, b);
	}
	ft_putstr_fd("[OK!]\n", 1);
	return (1);
}
