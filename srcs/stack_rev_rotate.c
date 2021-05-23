#include "push_swap.h"

t_stack	*stack_rev_rotate(t_stack *stack)
{
	t_stack	*temp;

	if (stack_size(stack) <= 1)
		return (stack);
	temp = stack->next;
	temp->prev = stack->prev;
	if (temp->prev)
		temp->prev->next = temp;
	stack->next = NULL;
	stack->prev = stack_last(temp);
	stack->prev->next = stack;
	stack = temp;
	return (stack);
}
