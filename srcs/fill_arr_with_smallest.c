#include "push_swap.h"

void	fill_arr_with_smallest(int *arr, t_stack *stack, int partition_size)
{
	int	i;

	i = 0;
	while (i < partition_size)
		arr[i++] = INT_MIN;
	i = 0;
	while (i < partition_size)
	{
		arr[i] = get_smallest_not_in_arr(stack, arr, partition_size);
		i++;
	}
}
