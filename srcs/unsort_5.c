#include "push_swap.h"

static t_stack	*fifth_from_top(t_stack *stack);

t_stack	*unsort_5(t_stack *stack, int a_or_b)
{
	t_stack	*helper;

	helper = NULL;
	if (!stack)
		return (NULL);
	stack = fifth_from_top(stack);
	while (stack_size(stack) > 3)
	{
		stack = stack_first(stack);
		stack = biggest_to_top(stack, a_or_b);
		stack_run_push(a_or_b, &stack, &helper);
		stack = fifth_from_top(stack);
	}
	stack = unsort_3(stack, a_or_b);
	while (stack_size(helper))
		stack_run_push(!a_or_b, &helper, &stack);
	stack = fifth_from_top(stack);
	if (!is_unsorted(stack))
		stack = stack_run(SWAP, a_or_b, stack);
	stack = stack_first(stack);
	return (stack);
}

static t_stack	*fifth_from_top(t_stack *stack)
{
	t_stack	*current;
	int		i;

	current = stack_last(stack);
	i = 0;
	while (i < 5 && current->prev)
	{
		current = current->prev;
		i++;
	}
	return (current);
}
