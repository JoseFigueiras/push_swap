#include "push_swap.h"

t_stack	*sort_5(t_stack *stack, int a_or_b)
{
	t_stack	*other_stack;

	if (is_sorted(stack))
		return (stack);
	other_stack = NULL;
	stack = smallest_to_top(stack, a_or_b);
	stack_run_push(a_or_b, &stack, &other_stack);
	stack = smallest_to_top(stack, a_or_b);
	stack_run_push(a_or_b, &stack, &other_stack);
	stack = sort_3(stack, a_or_b);
	stack_run_push(!a_or_b, &other_stack, &stack);
	stack_run_push(!a_or_b, &other_stack, &stack);
	if (!is_sorted(stack))
		stack = stack_run(SWAP, !a_or_b, stack);
	return (stack);
}
