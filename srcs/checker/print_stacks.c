#include "checker.h"

static size_t	stack_count_back(t_stack *stack);

void	print_stacks(t_stack *a, t_stack *b)
{
	t_stack	*acurrent;
	t_stack	*bcurrent;
	size_t	count_back_a;
	size_t	count_back_b;

	acurrent = stack_last(a);
	bcurrent = stack_last(b);
	while (acurrent || bcurrent)
	{
		count_back_a = stack_count_back(acurrent);
		count_back_b = stack_count_back(bcurrent);
		if (count_back_a >= count_back_b && count_back_a > 0)
		{
			ft_putnbr_fd(acurrent->item, 1);
			acurrent = acurrent->prev;
		}
		else
			ft_putchar_fd(' ', 1);
		ft_putchar_fd(' ', 1);
		if (count_back_b >= count_back_a && count_back_b > 0)
		{
			ft_putnbr_fd(bcurrent->item, 1);
			bcurrent = bcurrent->prev;
		}
		else
			ft_putchar_fd(' ', 1);
		ft_putchar_fd('\n', 1);
	}
	ft_putstr_fd("- -\n", 1);
	ft_putstr_fd("a b\n", 1);
}

static size_t	stack_count_back(t_stack *stack)
{
	t_stack	*current;
	size_t	i;

	current = stack;
	i = 0;
	while (current)
	{
		current = current->prev;
		i++;
	}
	return (i);
}
