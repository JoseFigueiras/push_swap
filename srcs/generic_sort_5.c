#include "push_swap.h"

t_stack	*generic_sort_5(t_stack *stack, int a_or_b)
{
	t_stack	*helper;

	helper = NULL;
	if (!stack)
		return (NULL);
	while (stack_size(stack) > 3)
	{
		stack = smallest_to_top(stack, a_or_b);
		stack_run_push(a_or_b, &stack, &helper);
	}
	stack = sort_3(stack, a_or_b);
	while (stack_size(helper))
		stack_run_push(!a_or_b, &helper, &stack);
	if (!is_sorted(stack))
		stack = stack_run(SWAP, a_or_b, stack);
	return (stack);
}
