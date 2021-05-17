#include "push_swap.h"

size_t	stack_size(t_stack *stack)
{
	size_t	i;

	stack = stack_first(stack);
	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
