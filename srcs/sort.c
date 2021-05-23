#include "push_swap.h"

t_stack	*sort(t_stack *stack, int a_or_b)
{
	size_t	size;

	size = stack_size(stack);
	if (!stack || !size)
		return (NULL);
	if (is_sorted(stack))
		return (stack);
	stack = cool_sort(stack, a_or_b);
	return (stack);
}
