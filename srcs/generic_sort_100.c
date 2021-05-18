#include "push_swap.h"

t_stack	*generic_sort_100(t_stack *stack, int a_or_b)
{
	t_stack	*helper;

	helper = NULL;
	if (!stack)
		return (NULL);
	while (stack_size(stack) > 5)
	{
		stack = smallest_to_top(stack, a_or_b);
		stack_run_push(a_or_b, &stack, &helper);
	}
	stack = generic_sort_5(stack, a_or_b);
	while (stack_size(helper)) 
		stack_run_push(!a_or_b, &helper, &stack);
	return (stack);
}
