#include "push_swap.h"

t_stack	*sort(t_stack *stack, int a_or_b)
{
	size_t	size;

	size = stack_size(stack);
	if (!stack || !size)
		return(NULL);
	if (is_sorted(stack))
		return (stack);
	if (size == 2)
		stack = sort_2(stack, a_or_b);
	else if (size <= 5)
		stack = generic_sort_5(stack, a_or_b);
	else if (size <= 100)
		stack = generic_sort_100(stack, a_or_b);
	else
		stack = generic_sort_200(stack, a_or_b);
	return (stack);
}
