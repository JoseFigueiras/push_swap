#include "checker.h"

t_stack	*stack_last(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}
