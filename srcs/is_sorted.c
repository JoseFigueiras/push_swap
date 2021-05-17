#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return (0);
	current = stack;
	while (current)
	{
		if (!current->prev)
			;
		else if (current->item > current->prev->item)
			return (0);
		current = current->next;
	}
	return (1);
}
