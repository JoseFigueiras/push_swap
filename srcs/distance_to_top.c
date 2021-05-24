#include "push_swap.h"

size_t	distance_to_top(int num, t_stack *stack)
{
	t_stack	*current;
	int		size;
	int		pos;
	size_t	distance;

	current = stack;
	pos = 1;
	while (current)
	{
		if (current->item == num)
			break ;
		pos++;
		current = current->next;
	}
	size = (int)stack_size(stack);
	if (size % 2 == 1 && pos > size / 2)
		distance = (size_t)absolute((size / 2) - absolute((size / 2) - pos
					+ 1));
	else
		distance = (size_t)absolute((size / 2) - absolute((size / 2) - pos));
	return (distance);
}
