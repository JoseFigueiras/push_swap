#include "checker.h"

t_stack	*stack_first(t_stack *stack)
{
	while (stack->prev)
		stack = stack->prev;
	return (stack);
}
