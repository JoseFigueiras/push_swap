#include "push_swap.h"

static void	push_arr_nums(t_stack **from, t_stack **to, int a_or_b, int *arr);
static int	is_in_arr(int num, int *arr);
static void	fill_arr_with_5_smallest(t_stack *stack, int *arr);

t_stack	*generic_sort(t_stack *stack, int a_or_b)
{
	t_stack	*helper;
	int		arr[5];

	helper = NULL;
	if (!stack)
		return (NULL);
	while (stack_size(stack) > 5)
	{
		fill_arr_with_5_smallest(stack, arr);
		push_arr_nums(&stack, &helper, a_or_b, arr);
		helper = unsort_5(helper, !a_or_b);
	}
	stack = sort_5(stack, a_or_b);
	while (helper)
		stack_run_push(!a_or_b, &helper, &stack);
	return (stack);
}

static void	push_arr_nums(t_stack **from, t_stack **to, int a_or_b, int *arr)
{
	int		i;
	int		j;
	int		top_or_bot;
	t_stack	*top;
	t_stack	*bot;

	i = 0;
	while (i < 5)
	{
		top = stack_last(*from);
		bot = *from;
		j = 0;
		while (1)
		{
			if (is_in_arr(top->item, arr))
			{
				top_or_bot = TOP;
				break ;
			}
			if (is_in_arr(bot->item, arr))
			{
				top_or_bot = BOT;
				j++;
				break ;
			}
			top = top->prev;
			bot = bot->next;
			j++;
		}
		while (j--)
		{
			if (top_or_bot == TOP)
				*from = stack_run(ROTATE, a_or_b, *from);
			else if (top_or_bot == BOT)
				*from = stack_run(REV_ROTATE, a_or_b, *from);
		}
		stack_run_push(a_or_b, from, to);
		//print_stacks(*from, *to);
		i++;
	}
}

static int	is_in_arr(int num, int *arr)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (num == arr[i])
			return (1);
		i++;
	}
	return (0);
}

static void	fill_arr_with_5_smallest(t_stack *stack, int *arr)
{
	t_stack	*current;
	int		temp;
	int		i;

	current = stack;
	temp = current->item;
	while (current)
	{
		if (current->item < temp)
			temp = current->item;
		current = current->next;
	}
	arr[0] = temp;
	i = 1;
	while (i < 5)
	{
		temp = INT_MAX;
		current = stack;
		while (current)
		{
			if (current->item < temp && current->item > arr[i - 1])
				temp = current->item;
			current = current->next;
		}
		arr[i++] = temp;
	}
}
