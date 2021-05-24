#include "push_swap.h"

int	from_arr_closest_to_top(t_stack *stack, int *arr, int partition_size)
{
	t_stack	*top;
	t_stack	*bot;

	top = stack_last(stack);
	bot = stack;
	while (top && bot)
	{
		if (is_in(top->item, arr, partition_size))
			return (top->item);
		if (is_in(bot->item, arr, partition_size))
			return (bot->item);
		top = top->prev;
		bot = bot->next;
	}
	exit(50);
	return (INT_MIN);
}
