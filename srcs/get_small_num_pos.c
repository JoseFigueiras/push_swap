#include "push_swap.h"

size_t	get_small_num_pos(t_stack *stack)
{
	t_stack	*current;
	size_t	pos;
	size_t	small_num_pos;
	int		small_num;

	pos = 1;
	current = stack;
	small_num = current->item;
	small_num_pos = pos;
	while (current)
	{
		if (current->item < small_num)
		{
			small_num = current->item;
			small_num_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (small_num_pos);
}
