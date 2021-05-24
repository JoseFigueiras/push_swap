#include "push_swap.h"

int	get_directly_below(t_stack *stack, int num)
{
	int		directly_below;
	t_stack	*current;

	if (!stack)
		exit(1);
	directly_below = INT_MIN;
	current = stack;
	while (current)
	{
		if (current->item > directly_below && current->item < num)
			directly_below = current->item;
		current = current->next;
	}
	if (directly_below == INT_MIN)
	{
		current = stack;
		while (current)
		{
			if (current->item > directly_below)
				directly_below = current->item;
			current = current->next;
		}
	}
	return (directly_below);
}
