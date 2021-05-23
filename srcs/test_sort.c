#include "push_swap.h"

static int		get_smallest(t_stack *stack);
static int		get_second_smallest(t_stack *stack);

t_stack	*test_sort(t_stack *stack, int a_or_b)
{
	int		small_num;
	int		big_num;
	t_stack	*helper;

	helper = NULL;
	while (stack_size(stack) > 5)
	{
		small_num = get_smallest(stack);
		big_num = get_second_smallest(stack);
		if (distance_to_top(small_num, stack) < distance_to_top(big_num, stack))
		{
			stack = get_num_to_top(small_num, stack, a_or_b);
			stack_run_push(a_or_b, &stack, &helper);
			stack = get_num_to_top(big_num, stack, a_or_b);
			stack_run_push(a_or_b, &stack, &helper);
		}
		else
		{
			stack = get_num_to_top(big_num, stack, a_or_b);
			stack_run_push(a_or_b, &stack, &helper);
			stack = get_num_to_top(small_num, stack, a_or_b);
			stack_run_push(a_or_b, &stack, &helper);
		}
		if (!is_unsorted(helper))
			stack_run(SWAP, !a_or_b, helper);
	}
	stack = sort_5(stack, a_or_b);
	while(stack_size(helper))
		stack_run_push(!a_or_b, &helper, &stack);
	return (stack);
}

static int		get_smallest(t_stack *stack)
{
	t_stack	*current;
	int		smallest;

	current = stack;
	smallest = current->item;
	while (current)
	{
		if (current->item < smallest)
			smallest = current->item;
		current = current->next;
	}
	return (smallest);
}

static int		get_second_smallest(t_stack *stack)
{
	t_stack	*current;
	int		smallest;
	int		second_smallest;

	if (stack_size(stack) < 2)
		return (INT_MIN);
	current = stack;
	smallest = get_smallest(stack);
	while (current)
	{
		if (current->item != smallest)
		{
			second_smallest = current->item;
			break ;
		}
		current = current->next;
	}
	current = stack;
	while (current)
	{
		if (current->item < second_smallest && current->item > smallest)
			second_smallest = current->item;
		current = current->next;
	}
	return (second_smallest);
}
