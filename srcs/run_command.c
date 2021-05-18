#include "push_swap.h"

static int	poop(t_stack **a, t_stack **b, char *line);

int	run_command(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "sa"))
		*a = stack_swap(*a);
	else if (!ft_strcmp(line, "sb"))
		*b = stack_swap(*b);
	else if (!ft_strcmp(line, "ss"))
	{
		*a = stack_swap(*a);
		*b = stack_swap(*b);
	}
	else if (!ft_strcmp(line, "pa"))
		stack_push(b, a);
	else if (!ft_strcmp(line, "pb"))
		stack_push(a, b);
	else
		return (poop(a, b, line));
	return (0);
}

static int	poop(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "ra"))
		*a = stack_rotate(*a);
	else if (!ft_strcmp(line, "rb"))
		*b = stack_rotate(*b);
	else if (!ft_strcmp(line, "rr"))
	{
		*a = stack_rotate(*a);
		*b = stack_rotate(*b);
	}
	else if (!ft_strcmp(line, "rra"))
		*a = stack_rev_rotate(*a);
	else if (!ft_strcmp(line, "rrb"))
		*b = stack_rev_rotate(*b);
	else if (!ft_strcmp(line, "rrr"))
	{
		*a = stack_rev_rotate(*a);
		*b = stack_rev_rotate(*b);
	}
	else
		return (0);
	return (1);
}
