#include "push_swap.h"

t_stack	*unsort_3(t_stack *stack, int a_or_b)
{
	size_t	small_num_pos;

	if (is_unsorted(stack))
		return (stack);
	small_num_pos = get_small_num_pos(stack);
	if (small_num_pos == 3)
	{
		stack = stack_run(ROTATE, a_or_b, stack);
		stack = unsort_2(stack, a_or_b);
	}
	else if (small_num_pos == 2)
	{
		stack = stack_run(REV_ROTATE, a_or_b, stack);
		if (!is_unsorted(stack))
			stack = stack_run(SWAP, a_or_b, stack);
	}
	else if (small_num_pos == 1)
		stack = unsort_2(stack, a_or_b);
	return (stack);
}
