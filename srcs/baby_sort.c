#include "push_swap.h"

static void	poop(t_stack **stack, t_stack **helper, int *arr,
				int partition_size);
static void	copy_remaining_to_helper(t_stack **stack, t_stack **helper,
				int a_or_b);

t_stack	*baby_sort(t_stack *stack, int a_or_b, int partition_size)
{
	int		*arr;
	t_stack	*helper;

	helper = NULL;
	arr = malloc(partition_size * sizeof(int));
	while (stack_size(stack) > (size_t)partition_size)
	{
		fill_arr_with_smallest(arr, stack, partition_size);
		poop(&stack, &helper, arr, partition_size);
	}
	free(arr);
	copy_remaining_to_helper(&stack, &helper, a_or_b);
	helper = biggest_to_top(helper, !a_or_b);
	while (helper)
		stack_run_push(!a_or_b, &helper, &stack);
	return (stack);
}

static void	poop(t_stack **stack, t_stack **helper, int *arr,
				int partition_size)
{
	int	i;
	int	closest;
	int	num_at_top;
	int	directly_below;

	i = 0;
	while (i < partition_size)
	{
		closest = from_arr_closest_to_top(*stack, arr, partition_size);
		*stack = get_num_to_top(closest, *stack, STACK_A);
		num_at_top = stack_last(*stack)->item;
		if (*helper)
		{
			directly_below = get_directly_below(*helper, num_at_top);
			*helper = get_num_to_top(directly_below, *helper, STACK_B);
		}
		stack_run_push(STACK_A, stack, helper);
		i++;
	}
}

static void	copy_remaining_to_helper(t_stack **stack, t_stack **helper,
				int a_or_b)
{
	int	num_at_top;
	int	directly_below;

	while (stack_size(*stack))
	{
		num_at_top = stack_last(*stack)->item;
		if (*helper)
		{
			directly_below = get_directly_below(*helper, num_at_top);
			*helper = get_num_to_top(directly_below, *helper, !a_or_b);
		}
		stack_run_push(a_or_b, stack, helper);
	}
}
