#include "push_swap.h"

t_stack	*stack_rotate(t_stack *stack)
{
	t_stack	*temp;

	if (stack_size(stack) <= 1)
		return (stack);
	temp = stack_last(stack);
	temp->prev->next = NULL;
	temp->prev = stack->prev;
	if (temp->prev)
		temp->prev->next = temp;
	temp->next = stack;
	stack->prev = temp;
	stack = temp;
	return (stack);
}
