#include "push_swap.h"

t_stack	*sort_3(t_stack *stack, int a_or_b)
{
	size_t	big_num_pos;

	if (is_sorted(stack))
		return (stack);
	big_num_pos = get_big_num_pos(stack);
	if (big_num_pos == 3)
	{
		stack = stack_run(ROTATE, a_or_b, stack);
		stack = sort_2(stack, a_or_b);
	}
	else if (big_num_pos == 2)
	{
		stack = stack_run(REV_ROTATE, a_or_b, stack);
		if (!is_sorted(stack))
			stack = stack_run(SWAP, a_or_b, stack);
	}
	else if (big_num_pos == 1)
		stack = sort_2(stack, a_or_b);
	return (stack);
}
