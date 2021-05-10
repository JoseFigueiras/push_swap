#include "checker.h"

t_stack	*stack_rev_rotate(t_stack *stack)
{
	t_stack	*temp;

	if (stack_size(stack) <= 1)
		return (stack);
	temp = stack;
	stack = stack->next;
	stack->prev = NULL;
	temp->next = NULL;
	stack_last(stack)->next = temp;
	return (stack);
}
