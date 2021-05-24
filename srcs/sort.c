#include "push_swap.h"

t_stack	*sort(t_stack *stack, int a_or_b)
{
	int	size;
	int	partition_size;

	size = (int)stack_size(stack);
	if (!stack || !size)
		return (NULL);
	if (is_sorted(stack))
		return (stack);
	if (size == 2)
		stack = sort_2(stack, a_or_b);
	if (size == 5)
		stack = sort_5(stack, a_or_b);
	if (size >= 100)
		partition_size = 20;
	if (size >= 500)
		partition_size = 35;
	if (is_sorted(stack))
		return (stack);
	stack = baby_sort(stack, a_or_b, partition_size);
	return (stack);
}
