#include "push_swap.h"

int	get_smallest_not_in_arr(t_stack *stack, int *arr, int partition_size)
{
	t_stack	*current;
	int		temp;

	temp = INT_MAX;
	current = stack;
	while (current)
	{
		if (current->item < temp && !is_in(current->item, arr, partition_size))
			temp = current->item;
		current = current->next;
	}
	return (temp);
}
