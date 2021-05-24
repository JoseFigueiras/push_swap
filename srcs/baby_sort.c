#include "push_swap.h"

static void	fill_arr_with_smallest(int *arr, t_stack *stack, int partition_size);
static int		get_smallest_not_in_arr(t_stack *stack, int *arr, int partition_size);
static int	from_arr_closest_to_top(t_stack *stack, int *arr, int partition_size);

t_stack	*baby_sort(t_stack *stack, int a_or_b, int partition_size)
{
	int		*arr;
	t_stack	*helper;
	int		closest;
	int		num_at_top;
	int		directly_below;
	int		i;

	helper = NULL;
	arr = malloc(partition_size * sizeof(int));
	while (stack_size(stack) > (size_t)partition_size)
	{
		fill_arr_with_smallest(arr, stack, partition_size);
		i = 0;
		while (i < partition_size)
		{
			closest = from_arr_closest_to_top(stack, arr, partition_size);
			stack = get_num_to_top(closest, stack, a_or_b);
			num_at_top = stack_last(stack)->item;
			if (helper)
			{
				directly_below = get_directly_below(helper, num_at_top);
				helper = get_num_to_top(directly_below, helper, !a_or_b);
			}
			stack_run_push(a_or_b, &stack, &helper);
			i++;
		}
	}
	free(arr);
	// copy remaining to helper
	while (stack_size(stack))
	{
		num_at_top = stack_last(stack)->item;
		if (helper)
		{
			directly_below = get_directly_below(helper, num_at_top);
			helper = get_num_to_top(directly_below, helper, !a_or_b);
		}
		stack_run_push(a_or_b, &stack, &helper);
	}
	// copy everything back to stack A
	helper = biggest_to_top(helper, !a_or_b);
	while (helper)
		stack_run_push(!a_or_b, &helper, &stack);
	return (stack);
}

static void	fill_arr_with_smallest(int *arr, t_stack *stack, int partition_size)
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

static int		get_smallest_not_in_arr(t_stack *stack, int *arr, int partition_size)
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

static int	from_arr_closest_to_top(t_stack *stack, int *arr, int partition_size)
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
