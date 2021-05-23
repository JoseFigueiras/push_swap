#include "push_swap.h"

static int	is_biggest_at_top(t_stack *stack);

t_stack	*biggest_to_top(t_stack *stack, int a_or_b)
{
	size_t	size;

	size = stack_size(stack);
	while (!is_biggest_at_top(stack))
	{
		if (get_big_num_pos(stack) <= size / 2)
			stack = stack_run(REV_ROTATE, a_or_b, stack);
		else
			stack = stack_run(ROTATE, a_or_b, stack);
	}
	return (stack);
}

static int	is_biggest_at_top(t_stack *stack)
{
	t_stack	*current;
	int		biggest;

	current = stack_last(stack);
	biggest = current->item;
	while (current)
	{
		if (current->item > biggest)
			return (0);
		current = current->prev;
	}
	return (1);
}
