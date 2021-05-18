#include "push_swap.h"

t_stack	*sort_2(t_stack *stack, int a_or_b)
{
	t_stack	*first;
	t_stack	*last;

	if (is_sorted(stack))
		return (stack);
	last = stack_last(stack);
	first = last->prev;
	if (last->item > first->item)
		stack = stack_run(SWAP, a_or_b, stack);
	return (stack);
}
