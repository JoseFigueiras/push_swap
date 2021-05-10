#include "checker.h"

t_stack	*stack_swap(t_stack *stack)
{
	t_stack	*current;
	int		temp;

	if (stack_size(stack) <= 1)
	{
		printf("Stack too smol\n");
		return (stack);
	}
	current = stack_last(stack);
	temp = current->item;
	current->item = current->prev->item;
	current->prev->item = temp;
	return (stack);
}
