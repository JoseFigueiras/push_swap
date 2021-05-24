#include "push_swap.h"

t_stack	*cool_sort(t_stack *stack, int a_or_b)
{
	t_stack	*helper;
	int		num_at_top;
	int		directly_below;

	helper = NULL;
	while (stack_size(stack))
	{
		num_at_top = stack_last(stack)->item;
		if (helper)
		{
			directly_below = get_directly_below(helper, num_at_top);
			helper = get_num_to_top(directly_below, helper, !a_or_b);
		}
		stack_run_push(a_or_b, &stack, &helper);
	}
	helper = biggest_to_top(helper, !a_or_b);
	while (helper)
		stack_run_push(!a_or_b, &helper, &stack);
	return (stack);
}
