#include "push_swap.h"

int	is_sorted(t_stack *a, t_stack *b)
{
	t_stack	*current;

	if (stack_size(b) != 0)
		return (0);
	current = a;
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
