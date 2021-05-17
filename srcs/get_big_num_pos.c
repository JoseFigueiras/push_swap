#include "push_swap.h"

size_t	get_big_num_pos(t_stack *stack)
{
	t_stack	*current;
	size_t	pos;
	size_t	big_num_pos;
	int		big_num;

	pos = 1;
	current = stack;
	big_num = current->item;
	big_num_pos = pos;
	while (current)
	{
		if (current->item > big_num)
		{
			big_num = current->item;
			big_num_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (big_num_pos);
}
